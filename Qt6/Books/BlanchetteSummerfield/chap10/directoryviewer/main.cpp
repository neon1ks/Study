#include "directoryviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DirectoryViewer directoryViewer;
    directoryViewer.show();

    return QApplication::exec();
}
