#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QLabel>
#include <QPainter>
#include <QSplashScreen>

static constexpr double LOAD_TIME_MSEC = 5000.;

static const int PROGRESS_X_PX = 272;
static const int PROGRESS_Y_PX = 333;
static const int PROGRESS_WIDTH_PX = 310;
static const int PROGRESS_HEIGHT_PX = 28;

static const int W = 200;
static const int H = 200;

auto main(int argc, char *argv[]) -> int
{
	QApplication a(argc, argv);

	QPixmap pix(":/images/splash.png");
	QSplashScreen splashScreen(pix);
	splashScreen.show();
	QApplication::processEvents();

	QElapsedTimer timer;
	timer.start();
	//qDebug() << "interval" << timer.elapsed();
	while (timer.elapsed() < LOAD_TIME_MSEC)
	{
		//qDebug() << "interval" << timer.elapsed();
		const int progress = static_cast<int>(static_cast<double>(timer.elapsed()) / LOAD_TIME_MSEC * 100.0);
		splashScreen.showMessage(QObject::tr("Загружено: %1%").arg(progress), Qt::AlignBottom | Qt::AlignRight);

		QPainter painter;
		painter.begin(&pix);

		painter.fillRect(PROGRESS_X_PX, PROGRESS_Y_PX, static_cast<int>(progress / 100.0 * PROGRESS_WIDTH_PX), PROGRESS_HEIGHT_PX, Qt::gray);

		painter.end();

		splashScreen.setPixmap(pix);
		QApplication::processEvents();
	}

	QLabel w;
	w.resize(W, H);
	w.setText(QObject::tr("Приложение запущено!"));
	w.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	w.show();

	splashScreen.finish(&w);

	return QApplication::exec();
}
