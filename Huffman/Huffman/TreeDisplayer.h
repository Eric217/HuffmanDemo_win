#pragma once
#include "Notifier.h"
#include <QMainWindow>
#include "ui_TreeDisplayer.h"
#include "TreePanel.h" 

class TreeDisplayer : public QMainWindow, public Notifier
{
	Q_OBJECT

public:
	TreeDisplayer(QWidget *parent = Q_NULLPTR);
	void transfer(QString &);

	QScrollArea * scroll;
	TreePanel * panel;

signals:
	void backToMain();
 
private:
	Ui::TreeDisplayer ui;
	QPoint * getLocations();

	private slots:
	void drawTree();
	void backButtonClicked();
	void saveCodePrint();
	void saveTreePrint();
};

