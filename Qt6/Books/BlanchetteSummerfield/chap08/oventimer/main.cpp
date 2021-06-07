#include "oventimer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    OvenTimer ovenTimer;
    ovenTimer.setWindowTitle(QObject::tr("Oven Timer"));
    ovenTimer.resize(300, 300);
    ovenTimer.show();

    return QApplication::exec();
}
