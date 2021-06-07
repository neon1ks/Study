#include "diagramwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DiagramWindow view;
    view.show();

    return QApplication::exec();
}
