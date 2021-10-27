#include <QtCore>

#include "currencymodel.h"

CurrencyModel::CurrencyModel(QObject *parent) : QAbstractTableModel(parent) { }

void CurrencyModel::setCurrencyMap(const QMap<QString, double> &map)
{
    currencyMap = map;
    //reset();
    beginResetModel();
    endResetModel();
}

int CurrencyModel::rowCount(const QModelIndex & /* parent */) const
{
    return static_cast<int>(currencyMap.count());
}

int CurrencyModel::columnCount(const QModelIndex & /* parent */) const
{
    return static_cast<int>(currencyMap.count());
}

QVariant CurrencyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    if (role == Qt::DisplayRole) {
        QString rowCurrency = currencyAt(index.row());
        QString columnCurrency = currencyAt(index.column());
        if (currencyMap.value(rowCurrency) == 0.0) {
            return "####";
        }
        double amount = currencyMap.value(columnCurrency)
                        / currencyMap.value(rowCurrency);
        return QString("%1").arg(amount, 0, 'f', 4);
    }
    return QVariant();
}

QVariant CurrencyModel::headerData(
        int section, Qt::Orientation /* orientation */, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    return currencyAt(section);
}

QString CurrencyModel::currencyAt(qsizetype offset) const
{
    auto iter = currencyMap.begin();
    while (offset > 0) {
        ++iter;
        --offset;
    }
    return iter.key();
}
