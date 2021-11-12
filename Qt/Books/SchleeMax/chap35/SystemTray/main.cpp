#include <QtWidgets>

#include "systemtray.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    SystemTray st;

    QApplication::setQuitOnLastWindowClosed(false);

    return QApplication::exec();
}
