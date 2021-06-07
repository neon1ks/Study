#ifndef TRACKDELEGATE_H
#define TRACKDELEGATE_H

#include <QItemDelegate>

class TrackDelegate : public QItemDelegate
{
    Q_OBJECT

public:
    explicit TrackDelegate(int durationColumn, QObject *parent = nullptr);
    virtual ~TrackDelegate() = default;

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
            const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
            const QModelIndex &index) const override;
    void setEditorData(
            QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
            const QModelIndex &index) const override;

private slots:
    void commitAndCloseEditor();

private:
    int durationColumn;
};

#endif // TRACKDELEGATE_H
