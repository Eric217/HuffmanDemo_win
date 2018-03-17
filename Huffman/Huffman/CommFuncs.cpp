#include "stdafx.h"
#include "CommFuncs.h"
#include "MinHeap.h"

int treeHeight = 0;
Dictionary<char, string> dict;

void resetProj() {
	treeHeight = 0;
	dict.reset(0);
}

void showErrorMessage(QString & msg) {
	QMessageBox::critical(0, "ALERT", msg, QMessageBox::Ok, 0);
}

int showQuestionMsg(QString & msg, QString & title1, QString & title2, QString & title3) {
	QMessageBox box(QMessageBox::Question, "Choose", msg);
	if (title3.isEmpty())
		box.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	else {
		box.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
		box.setButtonText(QMessageBox::Cancel, title3);
	}
	box.setButtonText(QMessageBox::Yes, title1);
	box.setButtonText(QMessageBox::No, title2);
	int result = box.exec();
	if (result == QMessageBox::Yes)
		return 1;
	else if (result == QMessageBox::No)
		return 2;
	else return 3;
}

void showInfoMessage(QString & msg) {
	QMessageBox::information(0, "INFO", msg, QMessageBox::Ok);
}

void fileExists(string & str, int postLength) {
	int c = 1;
	while (true) {
		const char * strcstr = str.c_str();
		QFileInfo fileInfo(QString(str.c_str()));
		if (fileInfo.isFile()) {
			int len = (int)str.length();
			if (c == 1) {
				char * arr = new char[len + 4];
				strncpy(arr, strcstr, len - postLength - 1); arr[len - postLength - 1] = '\0';
				//int b = 3, d = c; while (d /= 10) { b++; }
				//char * temp = new char[b]; 
				char temp[3];
				sprintf(temp, "(%d)", c);
				strcat(arr, temp);
				strcat(arr, str.substr(len - postLength - 1).c_str());
				arr[len + 3] = '\0';
				str = string(arr);
				delete[] arr;
			}
			else {
				char temp[1]; sprintf(temp, "%d", c);
				str.replace(len - 6, 1, temp);
			}
			c++;
		}
		else {
			break;
		}
	}
}

void append(string & str, char c) {
	long l = (long)str.length();
	const char *s = str.c_str();
	char * chs = new char[l + 2];
	for (long i = 0; i < l; i++) {
		chs[i] = s[i];
	}
	chs[l] = c;
	chs[l + 1] = '\0';
	str = string(chs);
	delete[] chs;
}

void append(string & str1, const string & str2) {
	long l1 = (long)str1.length(), l2 = (long)str2.length();
	long l = l1 + l2, i = 0;
	char * str = new char[l + 1];
	const char * str11 = str1.c_str();
	const char * str22 = str2.c_str();
	for (; i < l1; i++) {
		str[i] = str11[i];
	}
	for (long j = 0; j < l2; j++, i++) {
		str[i] = str22[j];
	}
	str[l] = '\0';
	str1 = string(str);
	delete[] str;
}

QString writeTo(const QString & path, const QString & content, const long & length ) {
	
	string temp = content.toStdString();
	string total;	
	ofstream f_out(path.toStdString(), ios::app);
	const char * arr = temp.c_str();
	
	for (long i = 0; i < length; i++) {	
		dict.objectForKey(arr[i], temp);
		total.append(temp);
		f_out << temp;
	}
	f_out.flush();
	f_out.close();
	return QString(total.c_str());
}

QPushButton * getRegularButton(QWidget * parent, int xx, int yy, string & key) {
	QPushButton * but = new QPushButton(parent);
	but->setGeometry(xx, yy, UnitSize, UnitSize);
	 
	but->setFont(QFont("Times", 26, QFont::Bold));
	
	const char * title = key.c_str();
	if (strcmp(title, Zero_Sign) == 0) {
		but->setText(" ");
		but->setEnabled(0);
	}
	else
		but->setText(QString(title));
	return but;
}

QString saveToWhere(const QString & defaultName) {
	 
	QString default = QString("./").append(defaultName);
	QString path = QFileDialog::getSaveFileName(0,QString("Save File"), default, QString("Texts (*.txt)"));
	if (!path.isEmpty()) {
		ofstream f_out(path.toStdString());
		if (!f_out.is_open()) {
			showErrorMessage(QString("No Right To Access"));
			return nil;
		}
		f_out.close();
		//QFile(path).remove();
		return path;
	}
	else
		return nil;
}

QString readFile() {
	QString path = QFileDialog::getOpenFileName(0, QString("Open File"), ".", QString("Text Files(*.txt)"));
	if (!path.isEmpty()) {
		QFile file(path);
		if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
			showErrorMessage(QString("No Right To Access"));
			return QString();
		}
		QTextStream in(&file);
		return in.readAll();
	}
	else
		return QString();
}

QString encode(const QString & content) {

	bool add;
	int charSetSize = 0;
	long length = content.length();

	int * weights = new int[length];
	char * charSet = new char[length];
	string str11 = content.toStdString();
	
	const char * arr = str11.c_str();

	for (long i = 0; i < length; i++) {
		add = 0; char c = arr[i];
	 
		for (int j = 0; j < charSetSize; j++)
			if (charSet[j] == c) {
				weights[j]++;
				add = 1; break;
			}
		if (!add) {
			charSet[charSetSize] = c;
			weights[charSetSize++] = 1;
		}
	}
 
	dict.reset(charSetSize);
  
	BinaryTree<char> tree = HuffmanTree(charSet, weights, charSetSize);

	tree.allPath();
	treeHeight = tree.height();

	tree.Delete();
	delete[] charSet;
	delete[] weights;
	
	int re = showQuestionMsg(QString("Save Before Display ?"), QString("Yes"), QString("No"), QString("Cancel"));
	if (re == 1) {
		QString filePath = saveToWhere(QString("codefile.txt"));
		if (filePath.isEmpty()) {
			resetProj();
			return nil;
		}
		QString binaryStr = writeTo(filePath, content, length);
		if (binaryStr.isEmpty()) 
			printf("debug");
		dict.localize1(filePath.toStdString());
		return binaryStr;
	}
	else if (re == 2) {
		string temp, conten = content.toStdString();
		QString total = nil;
		const char * arr = conten.c_str();
		for (long i = 0; i < length; i++) {
			dict.objectForKey(arr[i], temp);
			total.append(temp.c_str());
		}
		return total;
	}
	resetProj();
	return nil;
}

int decode(const QString & binary, const QString & hfmTree) {
 
	//mark: - »ñµÃ×Öµä
	QStringList list = hfmTree.split(QString(HFMLINE), QString::SkipEmptyParts);
	long s = list.size(), maxH = 0;
	dict.reset(s);
	string temp;
	for (int i = 0; i < s; i++) {
		temp = list[i].toStdString();
		int h = temp.length() - 1;
		if (maxH < h)
			maxH = h;
		const char * arr = temp.c_str();
		dict.setValueForKey(arr[0], temp.substr(2));
	}
	treeHeight = maxH;
	Dictionary<string, char> reversedDict;
	dict.reverseTo(reversedDict);
	
	//mark: - ½âÂë
	temp = binary.toStdString();
	s = binary.length();
	const char * arr = temp.c_str();
	QString text, t;	char c;
	 
	for (long i = 0; i < s; i++) {
		t.append(arr[i]);
		if (reversedDict.objectForKey(t.toStdString(), c)) {
			text.append(c);
			t.clear();
		}
	}
	if (text.isEmpty()) {
		showErrorMessage(QString("Decoder Does Not Match"));
		return -1;
	}
	 
	int re = showQuestionMsg(QString("Save TextFile Before Display ?"), QString("Yes"), QString("No"), QString("Cancel"));
	 
	if (re == 1) {
		QString filePath = saveToWhere(QString("textfile.txt"));
		if (filePath.isEmpty()) {
			resetProj();
			return -1;
		}
		ofstream f_out(filePath.toStdString(), ios::app);
		f_out << text.toStdString();
		f_out.close();
	}
	else if (re == 3) 
		return -1;
	return 1;
}