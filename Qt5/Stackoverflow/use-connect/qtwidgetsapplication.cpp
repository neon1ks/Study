#include "qtwidgetsapplication.h"
#include "ui_qtwidgetsapplication.h"

#include <QMessageBox>

QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QWidget(parent), ui(new Ui::QtWidgetsApplication)
{
    ui->setupUi(this);
    connect(ui->input, &QPushButton::clicked, this,
            &QtWidgetsApplication::inputUser);
    connect(ui->login, &QLineEdit::textChanged, &user, &User::setName);
    connect(ui->password, &QLineEdit::textChanged, &user, &User::setPassword);
}

QtWidgetsApplication::~QtWidgetsApplication()
{
    delete ui;
}

void QtWidgetsApplication::inputUser()
{
    if (user.getName() == "John" && user.getPassword() == "1234") {
        QMessageBox::information(this, "Programm", "You are our employee!");
    }

    else {
        QMessageBox::warning(this, "Program", "ERROR!");
    }
}
