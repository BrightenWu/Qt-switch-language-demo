#include "QLanguage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QLanguageTest1 w;
	w.show();
	return a.exec();
}
