#ifndef QTWIDGETSAPPLICATION_H
#define QTWIDGETSAPPLICATION_H

#include <QWidget>

#include "user.h"

namespace Ui {
class QtWidgetsApplication;
}

class QtWidgetsApplication : public QWidget
{
    Q_OBJECT

public:
    explicit QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

public slots:
    void inputUser();

private:
    Ui::QtWidgetsApplication *ui;
    User user;
};

#endif // QTWIDGETSAPPLICATION_H
