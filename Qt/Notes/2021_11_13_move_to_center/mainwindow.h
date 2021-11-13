#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QPushButton;
class QHBoxLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QPushButton *m_first;
    QPushButton *m_second;
    QHBoxLayout *m_layout;

private slots:
    void moveToCenter1();
    void moveToCenter2();
};
#endif // MAINWINDOW_H
