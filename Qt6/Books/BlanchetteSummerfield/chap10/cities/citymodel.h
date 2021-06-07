#ifndef CITYMODEL_H
#define CITYMODEL_H

#include <QAbstractTableModel>
#include <QStringList>
#include <QVector>

class CityModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CityModel(QObject *parent = nullptr);
    virtual ~CityModel() = default;

    void setCities(const QStringList &cityNames);

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(
            const QModelIndex &index, const QVariant &value, int role) override;
    QVariant headerData(
            int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    static int offsetOf(int row, int column);

    QStringList cities;
    QVector<int> distances;
};

#endif // CITYMODEL_H
