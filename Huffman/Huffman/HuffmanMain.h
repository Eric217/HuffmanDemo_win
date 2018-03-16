#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_HuffmanMain.h"

class HuffmanMain : public QMainWindow
{
	Q_OBJECT

public:
	HuffmanMain(QWidget *parent = Q_NULLPTR);

private:
	Ui::HuffmanMainClass ui;
};
