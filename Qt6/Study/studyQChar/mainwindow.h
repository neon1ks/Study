#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() = default;

public slots:
    void ParseText();

protected:
    QWidget *widget;
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
