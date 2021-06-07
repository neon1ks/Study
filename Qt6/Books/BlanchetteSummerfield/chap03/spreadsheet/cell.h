#ifndef CELL_H
#define CELL_H

#include <QTableWidgetItem>

// Каждый элемент `QTableWidgetItem` может иметь некоторые данные —
// до одного тика `QVariant` на каждую «роль» данных. НАиболее распространенными ролями являются
// `Qt::EditRole` и `Qt::DisplayRole` (роль правки и роль отображения)

class Cell : public QTableWidgetItem
{
public:
	Cell();

	QTableWidgetItem *clone() const;
	void setData(int role, const QVariant &value);
	QVariant data(int role) const;
	void setFormula(const QString &formula);
	QString formula() const;
	void setDirty();

private:
	QVariant value() const;
	QVariant evalExpression(const QString &str, int &pos) const;
	QVariant evalTerm(const QString &str, int &pos) const;
	QVariant evalFactor(const QString &str, int &pos) const;

	mutable QVariant cachedValue;

	// переменная `cacheIsDirty` принимает значение `true`, если кешируемое значение устарело
	mutable bool cacheIsDirty;
};

#endif
