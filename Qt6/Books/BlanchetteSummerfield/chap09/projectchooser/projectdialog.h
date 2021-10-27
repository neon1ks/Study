#ifndef PROJECTDIALOG_H
#define PROJECTDIALOG_H

#include <QDialog>

#include "ui_projectdialog.h"

class ProjectDialog : public QDialog, private Ui::ProjectDialog
{
    Q_OBJECT

public:
    ProjectDialog(QWidget *parent = nullptr);
    ~ProjectDialog() override = default;

public slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private:
    void moveCurrentItem(ProjectListWidget *source, ProjectListWidget *target);
};

#endif
