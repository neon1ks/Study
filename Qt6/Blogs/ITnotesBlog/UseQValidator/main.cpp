#include "validatordemo.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);
	ValidatorDemo w;
	w.show();
	return QApplication::exec();
}
