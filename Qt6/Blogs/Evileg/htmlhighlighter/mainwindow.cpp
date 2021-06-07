#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_htmlHightLighter = new HtmlHighLighter(ui->textEdit->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}
