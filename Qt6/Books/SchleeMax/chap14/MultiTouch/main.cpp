#include "MultiTouchWidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MultiTouchWidget wgt;
    wgt.resize(640, 480);
    wgt.show();

    return QApplication::exec();
}
