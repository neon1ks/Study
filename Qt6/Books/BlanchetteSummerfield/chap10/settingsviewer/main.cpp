#include "settingsviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingsViewer settingsViewer;
    settingsViewer.show();

    return QApplication::exec();
}
