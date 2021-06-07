#include <QDebug>
#include <QMetaType>
#include <QRect>
#include <QVariant>

// Шаблонная функция распаковки значений QVariant
template <typename T>
auto unpack(const QVariant &var, const T &defVal = T()) -> T
{
	if (var.isValid() && var.canConvert<T>())
	{
		return var.value<T>();
	}
	return defVal;
}

// Пользовательский тип в QVariant
class MyClass
{
public:
	MyClass()
	    : m_x(0)
	{
	}
	MyClass(int x)
	    : m_x(x)
	{
	}

	// Конструктор копирования и деструктор за нас создаст компилятор

	int get() const
	{
		return m_x;
	}

private:
	int m_x;
};

Q_DECLARE_METATYPE(MyClass)

// Динамические структуры на основе QVariant
class VariableContainer
{
public:
	template <typename T>
	void set(const QString &key, const T &val)
	{
		m_vals[key] = QVariant::fromValue(val);
	}

	template <typename T>
	T get(const QString &key, const T &defVal = T())
	{
		if (m_vals.contains(key))
		{
			return unpack<T>(m_vals[key], defVal);
		}
		return defVal;
	}

private:
	QHash<QString, QVariant> m_vals;
};

auto main() -> int
{
	QVariant var1(5);
	QVariant var2("Hello");
	QVariant var3(QRect(5, 5, 10, 10));

	qDebug() << var1.toInt();     // --> 5
	qDebug() << var2.toString();  // --> "Hello"
	qDebug() << var3.toRect();    // --> QRect(5,5 10x10)

	// Статический анализатор не рекомендует так делать:
	qDebug() << var1.value<int>();      // --> 5
	qDebug() << var2.value<QString>();  // --> "Hello"
	qDebug() << var3.value<QRect>();    // --> QRect(5,5 10x10)

	qDebug() << unpack(var2, QRect(1, 1, 1, 1));  // --> QRect(1,1 1x1)
	qDebug() << unpack(var3, QRect(1, 1, 1, 1));  // --> QRect(5,5 10x10)

	QVariant var4 = QVariant::fromValue(MyClass(94));
	// Используем нашу функцию unpack()
	qDebug() << unpack<MyClass>(var4).get();  // --> 94

	VariableContainer container;

	container.set("A", 5);
	container.set("B", 8.4);
	container.set("C", QPoint(3, 6));

	qDebug() << container.get<int>("A");     // --> 5
	qDebug() << container.get<float>("B");   // --> 8.4
	qDebug() << container.get<QPoint>("C");  // --> QPoint(3,6)

	return 0;
}
