#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "spell_text_edit.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow() = default;

protected:
    SpellTextEdit *spellTextEdit;
    QWidget *widget;
};
#endif // MAINWINDOW_H
