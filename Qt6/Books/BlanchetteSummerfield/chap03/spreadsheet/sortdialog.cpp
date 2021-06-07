#include "sortdialog.h"
#include "./ui_sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SortDialog)
{
	ui->setupUi(this);

	ui->secondaryGroupBox->hide();
	ui->tertiaryGroupBox->hide();

	layout()->setSizeConstraint(QLayout::SetFixedSize);

	setColumnRange('A', 'Z');
}

SortDialog::~SortDialog()
{
	delete ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
	ui->primaryColumnCombo->clear();
	ui->secondaryColumnCombo->clear();
	ui->tertiaryColumnCombo->clear();

	ui->secondaryColumnCombo->addItem(tr("None"));
	ui->tertiaryColumnCombo->addItem(tr("None"));
	ui->primaryColumnCombo->setMinimumSize(ui->secondaryColumnCombo->sizeHint());
	QChar ch = first;
	while (ch <= last)
	{
		ui->primaryColumnCombo->addItem(QString(ch));
		ui->secondaryColumnCombo->addItem(QString(ch));
		ui->tertiaryColumnCombo->addItem(QString(ch));
		ch = QChar(ch.unicode() + 1);
	}
}

auto SortDialog::getPrimaryColumnIndex() -> int
{
	return ui->primaryColumnCombo->currentIndex();
}

auto SortDialog::getSecondaryColumnIndex() -> int
{
	return ui->secondaryColumnCombo->currentIndex() - 1;
}

auto SortDialog::getTertiaryColumnIndex() -> int
{
	return ui->tertiaryColumnCombo->currentIndex() - 1;
}

auto SortDialog::getPrimaryAscending() -> bool
{
	return ui->primaryOrderCombo->currentIndex() == 0;
}

auto SortDialog::getSecondaryAscending() -> bool
{
	return ui->secondaryOrderCombo->currentIndex() == 0;
}

auto SortDialog::getTertiaryAscending() -> bool
{
	return ui->tertiaryOrderCombo->currentIndex() == 0;
}
