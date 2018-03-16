/********************************************************************************
** Form generated from reading UI file 'HuffmanMain.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUFFMANMAIN_H
#define UI_HUFFMANMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuffmanMainClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *codeTab;
    QLabel *label_6;
    QTextEdit *textView;
    QLabel *label_8;
    QTextEdit *encodeHfmTextV;
    QPushButton *textUploadButton;
    QPushButton *treeUpload_en;
    QWidget *decodeTab;
    QTextEdit *binaryTxtView;
    QLabel *label_12;
    QLabel *label_10;
    QTextEdit *decodeHfmTextV;
    QPushButton *binaryUploadButton_2;
    QPushButton *treeUpload_de;
    QToolButton *displayButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HuffmanMainClass)
    {
        if (HuffmanMainClass->objectName().isEmpty())
            HuffmanMainClass->setObjectName(QStringLiteral("HuffmanMainClass"));
        HuffmanMainClass->resize(800, 600);
        HuffmanMainClass->setIconSize(QSize(26, 23));
        centralWidget = new QWidget(HuffmanMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(300, 46, 177, 48));
        label->setStyleSheet(QStringLiteral("font: 25 28pt \"Microsoft YaHei UI Light\";"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(190, 130, 421, 351));
        tabWidget->setStyleSheet(QLatin1String("font: 25 16pt \"Microsoft YaHei UI Light\";\n"
"background-color:rgba(255,255,255,0.1);"));
        codeTab = new QWidget();
        codeTab->setObjectName(QStringLiteral("codeTab"));
        label_6 = new QLabel(codeTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 5, 259, 21));
        label_6->setStyleSheet(QStringLiteral("font: 25 16pt \"Microsoft YaHei UI\";"));
        textView = new QTextEdit(codeTab);
        textView->setObjectName(QStringLiteral("textView"));
        textView->setGeometry(QRect(10, 33, 394, 111));
        textView->setMaximumSize(QSize(16777215, 141));
        textView->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft JhengHei UI Light\";"));
        label_8 = new QLabel(codeTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 150, 371, 21));
        label_8->setStyleSheet(QStringLiteral("font: 25 12pt \"Microsoft YaHei UI\";"));
        encodeHfmTextV = new QTextEdit(codeTab);
        encodeHfmTextV->setObjectName(QStringLiteral("encodeHfmTextV"));
        encodeHfmTextV->setGeometry(QRect(10, 180, 391, 118));
        encodeHfmTextV->setMaximumSize(QSize(16777215, 16000000));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft JhengHei UI Light"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(3);
        encodeHfmTextV->setFont(font);
        encodeHfmTextV->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft JhengHei UI Light\";"));
        textUploadButton = new QPushButton(codeTab);
        textUploadButton->setObjectName(QStringLiteral("textUploadButton"));
        textUploadButton->setGeometry(QRect(273, 5, 31, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../../Desktop/\346\226\260\345\273\272\346\226\207\344\273\266\345\244\271/resource/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        textUploadButton->setIcon(icon);
        textUploadButton->setIconSize(QSize(24, 24));
        textUploadButton->setFlat(true);
        treeUpload_en = new QPushButton(codeTab);
        treeUpload_en->setObjectName(QStringLiteral("treeUpload_en"));
        treeUpload_en->setGeometry(QRect(376, 150, 31, 21));
        treeUpload_en->setIcon(icon);
        treeUpload_en->setIconSize(QSize(26, 23));
        treeUpload_en->setFlat(true);
        tabWidget->addTab(codeTab, QString());
        decodeTab = new QWidget();
        decodeTab->setObjectName(QStringLiteral("decodeTab"));
        binaryTxtView = new QTextEdit(decodeTab);
        binaryTxtView->setObjectName(QStringLiteral("binaryTxtView"));
        binaryTxtView->setGeometry(QRect(10, 30, 391, 111));
        binaryTxtView->setMaximumSize(QSize(16777215, 141));
        binaryTxtView->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft JhengHei UI Light\";"));
        label_12 = new QLabel(decodeTab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 150, 301, 21));
        label_12->setStyleSheet(QStringLiteral("font: 25 12pt \"Microsoft YaHei UI\";"));
        label_10 = new QLabel(decodeTab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 5, 321, 21));
        label_10->setStyleSheet(QStringLiteral("font: 25 16pt \"Microsoft YaHei UI\";"));
        decodeHfmTextV = new QTextEdit(decodeTab);
        decodeHfmTextV->setObjectName(QStringLiteral("decodeHfmTextV"));
        decodeHfmTextV->setGeometry(QRect(10, 180, 391, 121));
        decodeHfmTextV->setMaximumSize(QSize(16777215, 111111));
        decodeHfmTextV->setFont(font);
        decodeHfmTextV->setStyleSheet(QStringLiteral("font: 25 10pt \"Microsoft JhengHei UI Light\";"));
        binaryUploadButton_2 = new QPushButton(decodeTab);
        binaryUploadButton_2->setObjectName(QStringLiteral("binaryUploadButton_2"));
        binaryUploadButton_2->setGeometry(QRect(320, 5, 31, 21));
        binaryUploadButton_2->setIcon(icon);
        binaryUploadButton_2->setIconSize(QSize(24, 24));
        binaryUploadButton_2->setFlat(true);
        treeUpload_de = new QPushButton(decodeTab);
        treeUpload_de->setObjectName(QStringLiteral("treeUpload_de"));
        treeUpload_de->setGeometry(QRect(300, 150, 31, 21));
        treeUpload_de->setIcon(icon);
        treeUpload_de->setIconSize(QSize(24, 24));
        treeUpload_de->setFlat(true);
        tabWidget->addTab(decodeTab, QString());
        displayButton = new QToolButton(centralWidget);
        displayButton->setObjectName(QStringLiteral("displayButton"));
        displayButton->setGeometry(QRect(308, 487, 181, 52));
        displayButton->setStyleSheet(QStringLiteral("font: 25 26pt \"Microsoft YaHei UI Light\";"));
        displayButton->setAutoRaise(true);
        HuffmanMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HuffmanMainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        HuffmanMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HuffmanMainClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HuffmanMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(HuffmanMainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HuffmanMainClass->setStatusBar(statusBar);

        retranslateUi(HuffmanMainClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(HuffmanMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *HuffmanMainClass)
    {
        HuffmanMainClass->setWindowTitle(QApplication::translate("HuffmanMainClass", "Huffman", nullptr));
        label->setText(QApplication::translate("HuffmanMainClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt;\">HUFFMAN</span></p></body></html>", nullptr));
        label_6->setText(QApplication::translate("HuffmanMainClass", "<html><head/><body><p><span style=\" font-size:12pt;\">Please input your words or upload:</span></p></body></html>", nullptr));
        textView->setHtml(QApplication::translate("HuffmanMainClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft JhengHei UI Light'; font-size:10pt; font-weight:24; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_8->setText(QApplication::translate("HuffmanMainClass", "If there is, please input relative coding or upload:", nullptr));
        textUploadButton->setText(QString());
        treeUpload_en->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(codeTab), QApplication::translate("HuffmanMainClass", "CODE", nullptr));
        label_12->setText(QApplication::translate("HuffmanMainClass", "Please input relative coding or upload:", nullptr));
        label_10->setText(QApplication::translate("HuffmanMainClass", "<html><head/><body><p><span style=\" font-size:12pt;\">Please input your binary string or upload:</span></p></body></html>", nullptr));
        binaryUploadButton_2->setText(QString());
        treeUpload_de->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(decodeTab), QApplication::translate("HuffmanMainClass", "DECODE", nullptr));
        displayButton->setText(QApplication::translate("HuffmanMainClass", "DISPLAY \343\200\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HuffmanMainClass: public Ui_HuffmanMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMANMAIN_H
