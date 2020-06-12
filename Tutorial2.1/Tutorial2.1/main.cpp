#include "tutorial.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Tutorial w;
	w.show();
	return a.exec();
}
