#include "stdafx.h"
#include "HuffmanMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	HuffmanMain w;
	w.show();
	return a.exec();
}
