#include <QApplication>
#include "qtwidgetsapplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *widget = new QtWidgetsApplication();
    widget->show();

    return a.exec();
}
