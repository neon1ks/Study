#include "gotocelldialog.h"
#include "./ui_gotocelldialog.h"

#include <QtWidgets/QPushButton>

#include <QRegularExpression>
#include <QValidator>

GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GoToCellDialog)
{
	ui->setupUi(this);
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

	//QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
	//lineEdit->setValidator(new QRegExpValidator(regExp, this));

	QRegularExpression rx("[A-Za-z][1-9][0-9]{0,2}");
	QValidator *validator = new QRegularExpressionValidator(rx, this);
	ui->lineEdit->setValidator(validator);

	connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
	connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

GoToCellDialog::~GoToCellDialog()
{
	delete ui;
}

void GoToCellDialog::on_lineEdit_textChanged()
{
	ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ui->lineEdit->hasAcceptableInput());
}
