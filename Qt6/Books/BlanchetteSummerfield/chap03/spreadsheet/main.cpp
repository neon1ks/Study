#include "mainwindow.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);

	//auto *mainWin = new MainWindow;
	//mainWin->show();

	MainWindow mainWin;
	mainWin.show();

	return QApplication::exec();
}
