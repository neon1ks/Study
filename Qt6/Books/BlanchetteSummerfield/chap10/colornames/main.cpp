#include <QApplication>

#include <QHBoxLayout>

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include "colornamesdialog1.h"
#endif
#include "colornamesdialog2.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto *widget = new QWidget;
    auto *layout = new QHBoxLayout(widget);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    auto *dialog1 = new ColorNamesDialog1;
    layout->addWidget(dialog1);
#endif
    auto *dialog2 = new ColorNamesDialog2;
    layout->addWidget(dialog2);

    widget->show();

    return QApplication::exec();
}
