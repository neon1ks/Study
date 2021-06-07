#include <QDebug>
#include <QMetaType>
#include <QRect>
#include <QVariant>

const double DOUBLE_NUMBER = 5.5;

void check1()
{
	QVariant var1{ DOUBLE_NUMBER };
	QVariant var2{ "Hello" };

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	if (var1.type() == QVariant::Double)
	{
		qDebug() << var1.toDouble();
	}
	if (var2.type() == QVariant::String)
	{
		qDebug() << var2.toString();
	}
#else
	if (var1.metaType().id() == QMetaType::Double)
	{
		qDebug() << var1.toDouble();
	}
	if (var2.metaType().id() == QMetaType::QString)
	{
		qDebug() << var2.toString();
	}
#endif
}

auto main() -> int
{
	check1();
	return 0;
}
