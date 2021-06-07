#include "validatordemo.h"

#include <QDebug>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QValidator>

ValidatorDemo::ValidatorDemo(QWidget *parent)
    : QWidget(parent)
{
	auto *layout = new QVBoxLayout;

	auto *intEdit = new QLineEdit;
	edits << intEdit;
	// Валидатор целых чисел от 1000 до 3000
	intEdit->setValidator(new QIntValidator(IVMIN, IVMAX));
	layout->addWidget(intEdit);

	auto *doubleEdit = new QLineEdit;
	edits << doubleEdit;
	// Валидатор чисел с плавающей запятой от 5 до 15 с 2 знаками после запятой
	auto *doubleValidator = new QDoubleValidator(DVMIN, DVMAX, DECIMALS);
	doubleValidator->setNotation(QDoubleValidator::StandardNotation);
	doubleEdit->setValidator(doubleValidator);
	layout->addWidget(doubleEdit);

	auto *reEdit = new QLineEdit;
	edits << reEdit;
	// Валидатор по регулярному выражению для слов, начинающихся с заглавной буквы
	// длинной от 2 до 10 символов латинского алфавита
	QRegularExpression rx("[A-Z][a-z]{1,9}");
	QValidator *validator = new QRegularExpressionValidator(rx, this);
	reEdit->setValidator(validator);
	layout->addWidget(reEdit);

	auto *btn = new QPushButton(tr("Print"));
	connect(btn, SIGNAL(clicked()), SLOT(onPrint()));
	layout->addWidget(btn);

	setLayout(layout);
}

void ValidatorDemo::onPrint()
{
	foreach (QLineEdit *e, edits)
	{
		if (e->hasAcceptableInput())
		{
			// Если условие валидатора выполнено
			qDebug() << e->text();
		}
		else
		{
			// Если условие валидатора нарушено
			qDebug() << "Invalid";
		}
	}
}
