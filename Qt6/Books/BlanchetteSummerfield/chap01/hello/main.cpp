#include <QApplication>
#include <QLabel>

const int W = 240;
const int H = 70;

auto main(int argc, char *argv[]) -> int
{
	QApplication app(argc, argv);
	auto *label = new QLabel("<h2><i>Hello</i> "
	                         "<font color=red>Qt!</font></h2>");
	label->resize(W, H);
	label->setAlignment(Qt::AlignCenter);
	label->show();
	return QApplication::exec();
}
