#ifndef CURRENCYMODEL_H
#define CURRENCYMODEL_H

#include <QAbstractTableModel>
#include <QMap>

class CurrencyModel : public QAbstractTableModel
{
public:
    explicit CurrencyModel(QObject *parent = nullptr);
    virtual ~CurrencyModel() = default;

    void setCurrencyMap(const QMap<QString, double> &map);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(
            int section, Qt::Orientation orientation, int role) const override;

private:
    QString currencyAt(qsizetype offset) const;

    QMap<QString, double> currencyMap;
};

#endif
