#ifndef BOOLEANMODEL_H
#define BOOLEANMODEL_H

#include <QAbstractItemModel>

class Node;

class BooleanModel : public QAbstractItemModel
{
public:
    explicit BooleanModel(QObject *parent = nullptr);
    virtual ~BooleanModel();

    void setRootNode(Node *node);

    QModelIndex index(
            int row, int column, const QModelIndex &parent) const override;
    QModelIndex parent(const QModelIndex &child) const override;
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(
            int section, Qt::Orientation orientation, int role) const override;

private:
    Node *nodeFromIndex(const QModelIndex &index) const;

    Node *rootNode;
};

#endif // BOOLEANMODEL_H
