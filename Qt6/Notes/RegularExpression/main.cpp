#include <QCoreApplication>
#include <QDebug>

//#if QT_VERSION < 0x060000
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QRegExp>
#endif
#include <QRegularExpression>

void printResult(const QString &s, bool result)
{
	if (result)
	{
		qDebug() << s << " is true";
	}
	else
	{
		qDebug() << s << "is false";
	}
}

void testRegularExpression(const QString &pattern, const QStringList &tokens)
{

	qDebug() << "pattern = " << pattern;

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	qDebug() << "QRegExp";

	QRegExp regExp1(pattern);
	for (const auto &t : tokens)
	{
		printResult(t, regExp1.exactMatch(t));
	}

#endif

	qDebug() << "QRegularExpression";

	QString anchoredPattern = QRegularExpression::anchoredPattern(pattern);
	QRegularExpression regExp(anchoredPattern);
	for (const auto &t : tokens)
	{
		printResult(t, regExp.match(t).hasMatch());
	}
}

void test2()
{
	qDebug() << "\ntest2\n";

	QStringList tokens;
	tokens.append("A1");
	tokens.append("A12");
	tokens.append("A123");
	tokens.append("A1234");
	tokens.append("AB123");

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	qDebug() << "QRegExp";
	QRegExp re1("[A-Za-z][1-9][0-9]{0,2}");
	for (const auto &t : tokens)
	{
		printResult(t, re1.exactMatch(t));
	}
#endif

	qDebug() << "QRegularExpression";
	QRegularExpression re2("^[A-Za-z][1-9][0-9]{0,2}$");
	for (const auto &t : tokens)
	{
		printResult(t, re2.match(t).hasMatch());
	}
}

auto main() -> int
{

	QString pattern("[A-Za-z][1-9][0-9]{0,2}");

	QStringList tokens;
	tokens.append("A1");
	tokens.append("A12");
	tokens.append("A123");
	tokens.append("A1234");
	tokens.append("AB123");

	testRegularExpression(pattern, tokens);

	test2();

	return 0;
}
