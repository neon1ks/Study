#include "booleanwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BooleanWindow window;
    window.show();

    return QApplication::exec();
}
