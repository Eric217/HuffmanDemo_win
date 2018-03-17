#include "stdafx.h"
#include "TreeDisplayer.h"
#include "CommFuncs.h"
 
#include "LinkedSet.hpp"

TreeDisplayer::TreeDisplayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(1200, 900);
	scroll = new QScrollArea(this);
	scroll->setGeometry(180, 252, 921, 625);
	scroll->setAlignment(Qt::AlignCenter);
	scroll->setStyleSheet("background-image: url(:/HuffmanMain/Resources/background.png);");
	panel = 0;
	connect(ui.backButton, SIGNAL(clicked()), this, SLOT(backButtonClicked()));
	connect(ui.codePrintButton, SIGNAL(clicked()), this, SLOT(saveCodePrint()));
	connect(ui.treePrintButton, SIGNAL(clicked()), this, SLOT(saveTreePrint()));

}

void TreeDisplayer::transfer(QString & str) {
	 
	show();
	string temp = str.toStdString();
	const char * arr = temp.c_str();
	int len = str.length(), i = 0, j = 0;

	char buffer[50];
	ui.binaryView->clear();

	for (; j < len; i++, j++) {
		if (i == 50) {
			i -= 50;
			ui.binaryView->append(QString(buffer));
		}
		buffer[i] = arr[j];
	}
	buffer[i] = '\0';
	ui.binaryView->append(QString(buffer));
	drawTree();
}

//有字典就能画
void TreeDisplayer::drawTree() {
	QPoint *locations = getLocations();
	int contentH = locations[0].y() + UnitSize + 55;
	int unitNum = (int)pow(2, treeHeight - 1);
	int contentW = UnitSize * unitNum + SepaWidth * (unitNum + 1);
	if (panel)
		delete panel;
	panel = new TreePanel(this);
	panel->resize(contentW, contentH);

	LinkedSet<int> buttonSet;//装的是内部节点在 locations中的位置
	LinkedSet<QLine> legSet; //QLine重载了==，所以能直接用
						
	int delta = contentH - UnitSize; /// 坐标系

	//MARK: - 对树字典遍历
	for (int i = 0; i < dict.curSize; i++) {
		char key[2]; key[0] = dict.words[i].key; key[1] = '\0';
		const string & str = dict.words[i].value;
		int len = str.length(), result = 0;
		const char * strp = str.c_str();
		for (int j = 0; j < len; j++) {
			buttonSet.push(result);
			
			if (strp[j] == HFMLEFT) {
				QPoint st = QPoint(locations[result].x() + UnitSize / 2, contentH - locations[result].y());
				result = result * 2 + 1;
				QPoint en = QPoint(locations[result].x() + UnitSize, delta - locations[result].y());
				QLine _line = QLine(st, en);
				legSet.push(_line);
			}
			else {
				QPoint st = QPoint(locations[result].x() + UnitSize / 2, contentH - locations[result].y());
				result = result * 2 + 2;
				QPoint en = QPoint(locations[result].x(), delta - locations[result].y());
				QLine _line = QLine(st, en);
				legSet.push(_line);
			}
		}
		QPoint &pt = locations[result];
		QPushButton *but = getRegularButton(panel, pt.x(), delta - pt.y(), string(key));
	}
	//MARK: - 所有位置收集完毕，边交给paint，节点加子视图
	panel->setLegs(legSet);
	legSet.front = 0; //引用转移，防止析构两次
	Node<int> * tempN = buttonSet.front;
	while (tempN) {
		QPoint &pt = locations[tempN->data];
		QPushButton *but = getRegularButton(panel, pt.x(), delta - pt.y(), string(Zero_Sign));
		tempN = tempN->link;
	}
	free(locations);
	scroll->setWidget(panel);
	repaint();
}

QPoint * TreeDisplayer::getLocations() {
	int c = pow(2, treeHeight) - 1;
	QPoint *points = (QPoint *)malloc(c * sizeof(QPoint));
	//最底层单独确定位置
	int s = pow(2, treeHeight - 1) - 1;
	int bottom = 15;
	for (int i = s; i <= 2 * s; i++)
		points[i] = QPoint((i - s + 1)*SepaWidth + (i - s)*UnitSize, bottom);

	//其余层靠子树确定位置
	for (int i = treeHeight - 2; i >= 0; i--) {
		s = pow(2, i) - 1;
		for (int j = s; j <= 2 * s; j++) {
			int point1Idx = 2 * j + 1;
			int x1 = points[point1Idx].x() + UnitSize;
			float bian = points[point1Idx + 1].x() - x1;
			float x2 = x1 + bian / 2 - UnitSize / 2;
			float y2;
			if (j == s)
				y2 = points[point1Idx].y() + UnitSize + bian * cos(HeightAngle);
			else
				y2 = points[j - 1].y();
			points[j] = QPoint(x2, y2);
		}

	}
	return points;
}

void TreeDisplayer::backButtonClicked() {
	emit backToMain();
	hide();
}

void TreeDisplayer::saveCodePrint(){ 
	
	QString path = saveToWhere(QString("codeprint.txt"));
	if (path.isEmpty())	
		return;
	QString txt = ui.binaryView->toPlainText();
	ofstream f_out(path.toStdString(), ios::app);
	f_out << txt.toStdString();
	f_out.close();
}

void TreeDisplayer::saveTreePrint() {
	QString path = saveToWhere(QString("treeprint.txt"));
	if (path.isEmpty())
		return;
	dict.localize(path.toStdString());

}
