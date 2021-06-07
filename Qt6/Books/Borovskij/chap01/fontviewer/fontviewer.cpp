#include "fontviewer.h"

#include <QCheckBox>
#include <QComboBox>
#include <QFont>
#include <QFontDatabase>
#include <QLabel>
#include <QLayout>
#include <QSpinBox>
#include <QVBoxLayout>

FontViewer::FontViewer(QWidget *parent)
    : QDialog(parent)
{
	setWindowTitle(tr("Просмотр шрифтов"));
	resize(W, H);

	MainFormLayout = new QVBoxLayout(this);

	ChooseFontLayout = new QHBoxLayout();
	MainFormLayout->addLayout(ChooseFontLayout);

	SelectFontBox = new QComboBox(this);
	ChooseFontLayout->addWidget(SelectFontBox, 0, Qt::AlignTop);

	SetSize = new QSpinBox(this);
	SetSize->setMinimum(MIN_SIZE_FONT);
	SetSize->setMaximum(MAX_SIZE_FONT);
	SetSize->setValue(DEFAULT_SIZE_FONT);
	SetSize->setPrefix(tr("Высота "));
	QSizePolicy fixedSP = QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed, QSizePolicy::DefaultType);
	SetSize->setSizePolicy(fixedSP);
	ChooseFontLayout->addWidget(SetSize, 0, Qt::AlignTop);

	ViewTextLayout = new QHBoxLayout();
	MainFormLayout->addLayout(ViewTextLayout);

	SetFontGroup = new QVBoxLayout();

	SetBold = new QCheckBox(this);
	SetBold->setText(tr("Полужирный"));
	SetFontGroup->addWidget(SetBold);

	SetItalic = new QCheckBox(this);
	SetItalic->setText(tr("Курсив"));
	SetFontGroup->addWidget(SetItalic);

	ViewTextLayout->addLayout(SetFontGroup);

	TextLabel = new QLabel(this);
	TextLabel->setAlignment(Qt::AlignLeft);
	TextLabel->setText(tr("В чащах юга жил бы цитрус?\nДа, но фальшивый экземпляр."));
	ViewTextLayout->addWidget(TextLabel, 0, Qt::AlignTop);

	MainFormLayout->addStretch(1);

	connect(SelectFontBox, SIGNAL(activated(int)), this, SLOT(setLabelFont()));
	connect(SetSize, SIGNAL(valueChanged(int)), this, SLOT(setLabelFont()));
	connect(SetBold, SIGNAL(toggled(bool)), this, SLOT(setLabelFont()));
	connect(SetItalic, SIGNAL(toggled(bool)), this, SLOT(setLabelFont()));

	SelectFontBox->addItems(QFontDatabase::families());
	setLabelFont();
}

void FontViewer::setLabelFont()
{
	QString family = SelectFontBox->currentText();
	int size = SetSize->value();
	int weight = QFont::Normal;
	if (SetBold->isChecked())
		weight = QFont::DemiBold;
	bool italic = SetItalic->isChecked();
	QFont font(family, size, weight, italic);
	TextLabel->setFont(font);
}
