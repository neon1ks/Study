#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Подключаем базу данных
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/maksim/Temp/database.db3");
    db.open();

    //Осуществляем запрос
    QSqlQuery query;
    query.exec("SELECT _id, name, age FROM People");

    //Выводим значения из запроса
    while (query.next())
    {
        QString _id = query.value(0).toString();
        QString name = query.value(1).toString();
        QString age = query.value(2).toString();
        ui->textEdit->insertPlainText(_id+" "+name+" "+age+"\n");
    }
}

