#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class GoToCellDialog;
}
QT_END_NAMESPACE

class GoToCellDialog : public QDialog
{
	Q_OBJECT

public:
	GoToCellDialog(QWidget *parent = nullptr);
	~GoToCellDialog();

	QString getText();

private:
	Ui::GoToCellDialog *ui;

private slots:
	void on_lineEdit_textChanged();
};

#endif  // GOTOCELLDIALOG_H
