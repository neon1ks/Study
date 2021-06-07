#include "mainwindow.h"

#include <QHBoxLayout>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    auto *hLayout = new QHBoxLayout();
    textEdit = new QTextEdit(this);
    hLayout->addWidget(textEdit);

    widget = new QWidget;
    widget->setLayout(hLayout);
    setCentralWidget(widget);

    connect(textEdit, &QTextEdit::textChanged, this, &MainWindow::ParseText);
}

void MainWindow::ParseText()
{
    QString text = textEdit->toPlainText();
    auto len = text.count();
    if (len > 0) {
        qDebug() << text.at(len - 1) << text.at(len - 1).isLetterOrNumber();
    }
}
