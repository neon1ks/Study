#include "main_window.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto *hLayout = new QHBoxLayout();
    spellTextEdit = new SpellTextEdit(this);
    hLayout->addWidget(spellTextEdit);

    widget = new QWidget;
    widget->setLayout(hLayout);
    setCentralWidget(widget);
}
