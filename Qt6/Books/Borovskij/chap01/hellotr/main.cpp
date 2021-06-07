#include <QApplication>
#include <QLocale>
#include <QPushButton>
#include <QTranslator>

const int W = 100;
const int H = 30;

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);

	QTranslator translator;
	const QStringList uiLanguages = QLocale::system().uiLanguages();
	for (const QString &locale : uiLanguages)
	{
		const QString baseName = "hellotr_" + QLocale(locale).name();
		if (translator.load(":/i18n/" + baseName))
		{
			QApplication::installTranslator(&translator);
			break;
		}
	}
	QPushButton hello(QPushButton::tr("Hello world!"));
	hello.resize(W, H);
	hello.show();
	return QApplication::exec();
}
