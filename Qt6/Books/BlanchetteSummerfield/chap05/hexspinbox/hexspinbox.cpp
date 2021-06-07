#include <QtWidgets>

#include "hexspinbox.h"

HexSpinBox::HexSpinBox(QWidget *parent)
    : QSpinBox(parent)
{
	setRange(RANGE_MIN, RANGE_MAX);

	//validator = new QRegExpValidator(QRegExp("[0-9A-Fa-f]{1,8}"), this);

	QRegularExpression rx("[0-9A-Fa-f]{1,8}");
	validator = new QRegularExpressionValidator(rx, this);
}

// Функция вызывается для проверки допустимости введенного текста. Результат может иметь одно из трех значений:
// 1) Invalid (текст не соответствует регулярному значению
// 2) Intermediate (текст, вероятно, является частью допустимого значения)
// 3) Acceptable (текст допустим)

auto HexSpinBox::validate(QString &text, int &pos) const -> QValidator::State
{
	return validator->validate(text, pos);
}

auto HexSpinBox::valueFromText(const QString &text) const -> int
{
	bool ok{};
	return text.toInt(&ok, NUMBER_BASE);
}

auto HexSpinBox::textFromValue(int value) const -> QString
{
	return QString::number(value, NUMBER_BASE).toUpper();
}
