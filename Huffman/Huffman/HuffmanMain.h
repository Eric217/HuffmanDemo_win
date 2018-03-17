#pragma once
#include "Notifier.h"
#include <QtWidgets/QMainWindow>
#include "ui_HuffmanMain.h"
 
class HuffmanMain : public QMainWindow
{
	Q_OBJECT

public:
	HuffmanMain(QWidget *parent = Q_NULLPTR);
	
	Notifier * delegate;
	public slots:
	void receiveShow();

private:
	Ui::HuffmanMainClass ui;
	
	void readFileTo(QTextEdit *);

	private slots:

	void displayResult();

	void textUpload();
	void treeUpload_encode();
	void binaryUpload();
	void treeUpload_decode();
};
