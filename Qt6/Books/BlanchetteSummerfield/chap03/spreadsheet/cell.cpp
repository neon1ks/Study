#include <QtWidgets>

#include "cell.h"

Cell::Cell()
{
	cacheIsDirty = true;
	//setDirty();
}

auto Cell::clone() const -> QTableWidgetItem *
{
	return new Cell(*this);
}

void Cell::setData(int role, const QVariant &value)
{
	QTableWidgetItem::setData(role, value);
	if (role == Qt::EditRole)
		setDirty();
}

auto Cell::data(int role) const -> QVariant
{
	if (role == Qt::DisplayRole)
	{
		if (value().isValid())
		{
			return value().toString();
		}
		return "####";
	}
	if (role == Qt::TextAlignmentRole)
	{
		if (value().metaType().id() == QMetaType::QString)
		{
			return int(Qt::AlignLeft | Qt::AlignVCenter);
		}
		return int(Qt::AlignRight | Qt::AlignVCenter);
	}
	return QTableWidgetItem::data(role);
}

void Cell::setFormula(const QString &formula)
{
	setData(Qt::EditRole, formula);
}

auto Cell::formula() const -> QString
{
	return data(Qt::EditRole).toString();
}

void Cell::setDirty()
{
	cacheIsDirty = true;
}

const QVariant Invalid;

auto Cell::value() const -> QVariant
{
	if (cacheIsDirty)
	{
		cacheIsDirty = false;

		QString formulaStr = formula();
		if (formulaStr.startsWith('\''))
		{
			cachedValue = formulaStr.mid(1);
		}
		else if (formulaStr.startsWith('='))
		{
			cachedValue = Invalid;
			QString expr = formulaStr.mid(1);
			expr.replace(" ", "");
			expr.append(QChar::Null);

			int pos = 0;
			cachedValue = evalExpression(expr, pos);
			if (expr[pos] != QChar::Null)
				cachedValue = Invalid;
		}
		else
		{
			bool ok = true;
			double d = formulaStr.toDouble(&ok);
			if (ok)
			{
				cachedValue = d;
			}
			else
			{
				cachedValue = formulaStr;
			}
		}
	}
	return cachedValue;
}

// синтаксический анализатор называется парсер с рекурсивным спуском (recursive-descent parsers)
// Ecpression, Term, Factor — выражение, терм, фактор
auto Cell::evalExpression(const QString &str, int &pos) const -> QVariant
{
	QVariant result = evalTerm(str, pos);
	while (str[pos] != QChar::Null)
	{
		QChar op = str[pos];
		if (op != '+' && op != '-')
			return result;
		++pos;

		// Мы продолжаем эту процедуру, пока не закончатся термы. Это даст правильный результат,
		// потому что операции сложения и вычитания обладают свойством «ассоциативности слева»
		// (left-associative); то есть «1-2-3» означает «(1-2)-3», а не 1-(2-3)»
		QVariant term = evalTerm(str, pos);
		if (result.metaType().id() == QMetaType::Double && term.metaType().id() == QMetaType::Double)
		{
			if (op == '+')
			{
				result = result.toDouble() + term.toDouble();
			}
			else
			{
				result = result.toDouble() - term.toDouble();
			}
		}
		else
		{
			result = Invalid;
		}
	}
	return result;
}

auto Cell::evalTerm(const QString &str, int &pos) const -> QVariant
{
	QVariant result = evalFactor(str, pos);
	while (str[pos] != QChar::Null)
	{
		QChar op = str[pos];
		if (op != '*' && op != '/')
			return result;
		++pos;

		QVariant factor = evalFactor(str, pos);
		if (result.metaType().id() == QMetaType::Double && factor.metaType().id() == QMetaType::Double)
		{
			if (op == '*')
			{
				result = result.toDouble() * factor.toDouble();
			}
			else
			{
				// Нельзя допускать деление на нуль, так как это приводит к ошибке на некоторых процессорах.
				// Хотя не рекомендуется проверять равенство чисел с плавающей точкой из-за ошибки
				// округления, можно спокойно делать проверку на равенство значению 0.0
				// для предотвращения деления на нуль.
				if (factor.toDouble() == 0.0)
				{
					result = Invalid;
				}
				else
				{
					result = result.toDouble() / factor.toDouble();
				}
			}
		}
		else
		{
			result = Invalid;
		}
	}
	return result;
}

auto Cell::evalFactor(const QString &str, int &pos) const -> QVariant
{
	QVariant result;
	bool negative = false;

	if (str[pos] == '-')
	{
		negative = true;
		++pos;
	}

	if (str[pos] == '(')
	{
		++pos;
		result = evalExpression(str, pos);
		if (str[pos] != ')')
			result = Invalid;
		++pos;
	}
	else
	{
		QString token;
		QString pattern("[A-Za-z][1-9][0-9]{0,2}");
		pattern = QRegularExpression::anchoredPattern(pattern);
		QRegularExpression regExp(pattern);

		while (str[pos].isLetterOrNumber() || str[pos] == '.')
		{
			token += str[pos];
			++pos;
		}

		if (regExp.match(token).hasMatch())
		{
			int column = token[0].toUpper().unicode() - 'A';
			int row = QStringView{ token }.mid(1).toInt() - 1;

			Cell *c = dynamic_cast<Cell *>(
			    tableWidget()->item(row, column));
			if (c)
			{
				result = c->value();
			}
			else
			{
				result = 0.0;
			}
		}
		else
		{
			bool ok{};
			result = token.toDouble(&ok);
			if (!ok)
				result = Invalid;
		}
	}

	if (negative)
	{
		if (result.metaType().id() == QMetaType::Double)
		{
			result = -result.toDouble();
		}
		else
		{
			result = Invalid;
		}
	}
	return result;
}
