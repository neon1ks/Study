#include <QApplication>
#include <QPushButton>

const int W = 240;
const int H = 70;

auto main(int argc, char *argv[]) -> int
{
	QApplication app(argc, argv);
	auto *button = new QPushButton("Quit");
	QObject::connect(button, SIGNAL(clicked()), &app, SLOT(quit()));
	button->resize(W, H);
	button->show();
	return QApplication::exec();
}
