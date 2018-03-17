#include "stdafx.h"
#include "HuffmanMain.h"
#include "TreeDisplayer.h"
#include <QtWidgets/QApplication>
 
 
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	HuffmanMain w;
	TreeDisplayer d;
	w.delegate = &d;
	w.show();	 
	QObject::connect(&d, SIGNAL(backToMain()), &w, SLOT(receiveShow()));
	
	return a.exec();
}
