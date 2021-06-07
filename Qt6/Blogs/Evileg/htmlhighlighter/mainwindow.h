#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HTMLHighLighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

private:
    Ui::MainWindow *ui;
    HtmlHighLighter *m_htmlHightLighter;
};

#endif // MAINWINDOW_H
