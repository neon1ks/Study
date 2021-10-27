#include "imagetableviewdemowidget.h"
#include <QApplication>

int main( int argc, char* argv[] ) {
    QApplication a( argc, argv );
    ImageTableViewDemoWidget w;
    w.showMaximized();

    return a.exec();
}
