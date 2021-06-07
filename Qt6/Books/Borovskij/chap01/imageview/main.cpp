#include "imageview.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);
	ImageView w;
	w.show();
	return QApplication::exec();
}
