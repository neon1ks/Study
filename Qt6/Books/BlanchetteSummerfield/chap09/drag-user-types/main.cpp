#include "mytablewidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTableWidget w;
    w.show();
    return QApplication::exec();
}
