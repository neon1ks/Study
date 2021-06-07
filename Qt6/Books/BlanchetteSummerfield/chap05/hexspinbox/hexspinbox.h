#ifndef HEXSPINBOX_H
#define HEXSPINBOX_H

#include <QSpinBox>

class QRegExpValidator;

class HexSpinBox : public QSpinBox
{
	Q_OBJECT

public:
	HexSpinBox(QWidget *parent = nullptr);
	~HexSpinBox() = default;

protected:
	QValidator::State validate(QString &text, int &pos) const;
	int valueFromText(const QString &text) const;
	QString textFromValue(int value) const;

private:
	//QRegExpValidator *validator;
	QRegularExpressionValidator *validator;

	const int RANGE_MIN = 0;
	const int RANGE_MAX = 255;
	const int NUMBER_BASE = 16;
};
#endif  // HEXSPINBOX_H
