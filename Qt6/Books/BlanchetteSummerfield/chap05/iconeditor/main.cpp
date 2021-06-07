#include "iconeditor.h"

#include <QApplication>

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);
	IconEditor iconEditor;
	iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
	iconEditor.setIconImage(QImage(":/images/mouse.png"));
	iconEditor.show();
	return QApplication::exec();
}
