#include "timerdemowidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerDemoWidget w;
    w.resize( 100, 100 );
    w.show();
    return QApplication::exec();
}
