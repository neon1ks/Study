#ifndef VALIDATORDEMO_H
#define VALIDATORDEMO_H

#include <QLineEdit>
#include <QWidget>

class ValidatorDemo : public QWidget
{
	Q_OBJECT

public:
	ValidatorDemo(QWidget *parent = nullptr);
	virtual ~ValidatorDemo() = default;

private slots:
	void onPrint();

private:
	QVector<QLineEdit *> edits;

	static const int IVMIN = 1000;
	static const int IVMAX = 3000;
	static constexpr double DVMIN = 5.0;
	static constexpr double DVMAX = 25.0;
	static const int DECIMALS = 2;
};
#endif  // VALIDATORDEMO_H
