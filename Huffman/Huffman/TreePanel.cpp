#include "stdafx.h"
#include "TreePanel.h"


TreePanel::TreePanel(QWidget * parent) {
	setParent(parent);
}

void TreePanel::setLegs(LinkedSet<QLine> & lineSet) {
	legs.deinit();
	if (lineSet.size() == 0) 
		printf("qt-assert");
	legs = lineSet;
}

void TreePanel::paintEvent(QPaintEvent * event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	QPen p = painter.pen();
	p.setWidth(2);
	painter.setPen(p);
	Node<QLine> * temp = legs.front;
	while (temp) {
		painter.drawLine(temp->data);
		temp = temp->link;
	}

}

TreePanel::~TreePanel()
{
	legs.deinit();
}
