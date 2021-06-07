#include "iconeditor.h"

#include <QApplication>
#include <QScrollArea>

auto main(int argc, char *argv[]) -> int
{
    QApplication a(argc, argv);
    IconEditor iconEditor;
    iconEditor.setWindowTitle(QObject::tr("Icon Editor"));
    iconEditor.setIconImage(QImage(":/images/mouse.png"));
    QScrollArea scrollArea;
    scrollArea.setWidget(&iconEditor);
    scrollArea.viewport()->setBackgroundRole(QPalette::Dark);
    scrollArea.viewport()->setAutoFillBackground(true);
    scrollArea.setWindowTitle(QObject::tr("Icon Editor"));

    scrollArea.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    scrollArea.show();
    return QApplication::exec();
}
