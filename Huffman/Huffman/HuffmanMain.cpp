#include "stdafx.h"
 
#include "HuffmanTree.hpp"
#include "HuffmanMain.h"


HuffmanMain::HuffmanMain(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setFixedSize(800, 600);

	QString plhd = QString("e.g.\na:10\n  :15\n\\n:4\n\\t:9\n");
	ui.decodeHfmTextV->setPlaceholderText(plhd);
	ui.encodeHfmTextV->setPlaceholderText(plhd);
 
	connect(ui.textUploadButton, SIGNAL(clicked()), this, SLOT(textUpload()));
	connect(ui.treeUpload_en, SIGNAL(clicked()), this, SLOT(treeUpload_encode()));
	connect(ui.binaryUploadButton, SIGNAL(clicked()), this, SLOT(binaryUpload()));
	connect(ui.treeUpload_de, SIGNAL(clicked()), this, SLOT(treeUpload_decode()));

	connect(ui.displayButton, SIGNAL(clicked()), this, SLOT(displayResult()));
}

void HuffmanMain::displayResult() {
	
	int currentTab = ui.tabWidget->currentIndex();
	if (0 == currentTab) {
		QString text = ui.textView->toPlainText();
		if (text.isEmpty()) {
			showErrorMessage(QString("No Contents Found"));
			return;
		}
		QString hfm = ui.encodeHfmTextV->toPlainText();
		//if (hfm.isEmpty()) {
		if (1) {
			QString binaryStr = encode(text);
			if (!binaryStr.isEmpty()) {
 				delegate->transfer(binaryStr);
				hide();
			}
		}
		else {
	 
			QStringList arr = hfm.split(QChar('\n'), QString::SkipEmptyParts);
			int len = arr.length();
			for (int i = 0; i < len; i++) {
				QString & tempStr = arr[i];
				QStringList arr1 = tempStr.split(":");
				if (arr1.length() == 2) {
					if (arr1[0].length() == 2) { //\n

					}
					else {

					}
				}
				else {
					QStringList arr2 = tempStr.split("£º");
					if (arr2.length() == 2) {

					}
					else {
						//wrong
					}

				}
			}
			//compare and yes cancel
		}
	}
	else {

		QString text = ui.binaryTxtView->toPlainText();
		if (text.isEmpty()) {
			showErrorMessage(QString("No Contents Found"));
			return;
		}
		QString hfm = ui.decodeHfmTextV->toPlainText();
		if (hfm.isEmpty()) {
			showErrorMessage(QString("No Decoder"));
			return;
		}
		if (-1 == decode(text, hfm))
			return;

		delegate->transfer(text);
		hide();
	}
}

void HuffmanMain::readFileTo(QTextEdit * txtView) {
	QString fileContent = readFile();
	if (fileContent.isEmpty())
		return;
	QString txtViewContent = txtView->toPlainText();
	if (txtViewContent.isEmpty())
		txtView->setText(fileContent);
	else {
		int re = showQuestionMsg(QString("Merge Or Replace Existed Text ?"), QString("Merge"), QString("Replace"), QString("Cancel"));
		if (re == 1)
			txtView->append(fileContent);
		else if (re == 2)
			txtView->setText(fileContent);
	}
}

void HuffmanMain::receiveShow() {
	show();
}

void HuffmanMain::textUpload() {
	readFileTo(ui.textView);
}

void HuffmanMain::treeUpload_encode() {
	readFileTo(ui.encodeHfmTextV);
}

void HuffmanMain::binaryUpload() {
	readFileTo(ui.binaryTxtView);
}

void HuffmanMain::treeUpload_decode() {
	readFileTo(ui.decodeHfmTextV);
}
