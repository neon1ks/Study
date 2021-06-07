#include "fontviewer.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);
	FontViewer w;
	w.show();
	return QApplication::exec();
}
