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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuffmanMainClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HuffmanMainClass)
    {
        if (HuffmanMainClass->objectName().isEmpty())
            HuffmanMainClass->setObjectName(QStringLiteral("HuffmanMainClass"));
        HuffmanMainClass->resize(600, 400);
        menuBar = new QMenuBar(HuffmanMainClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HuffmanMainClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HuffmanMainClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HuffmanMainClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HuffmanMainClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HuffmanMainClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HuffmanMainClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HuffmanMainClass->setStatusBar(statusBar);

        retranslateUi(HuffmanMainClass);

        QMetaObject::connectSlotsByName(HuffmanMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *HuffmanMainClass)
    {
        HuffmanMainClass->setWindowTitle(QApplication::translate("HuffmanMainClass", "HuffmanMain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HuffmanMainClass: public Ui_HuffmanMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMANMAIN_H
