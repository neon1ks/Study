#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>

const int W = 240;
const int H = 70;

auto main(int argc, char *argv[]) -> int
{
	QApplication app(argc, argv);

	auto *window = new QWidget;
	window->setWindowTitle("Enter Your Age");
	window->resize(W, H);

	auto *spin_box = new QSpinBox;
	auto *slider = new QSlider(Qt::Horizontal);

	spin_box->setRange(0, 130);
	slider->setRange(0, 130);
	QObject::connect(spin_box, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
	QObject::connect(slider, SIGNAL(valueChanged(int)), spin_box, SLOT(setValue(int)));

	spin_box->setValue(35);

	auto *layout = new QHBoxLayout;
	layout->addWidget(spin_box);
	layout->addWidget(slider);

	window->setLayout(layout);
	window->show();

	return QApplication::exec();
}
