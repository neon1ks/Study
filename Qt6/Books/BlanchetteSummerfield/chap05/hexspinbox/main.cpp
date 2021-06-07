#include "hexspinbox.h"

#include <QApplication>

const int W = 200;
const int H = 100;

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);
	HexSpinBox spinBox;
	spinBox.setWindowTitle(QObject::tr("Hex Spin Box"));
	spinBox.resize(W, H);

	QFont font;
	font.setPointSize(48);
	spinBox.setFont(font);

	spinBox.show();
	return QApplication::exec();
}
