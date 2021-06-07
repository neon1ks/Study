#ifndef COORDINATESETTER_H
#define COORDINATESETTER_H

#include <QDialog>
#include <QList>
#include <QPointF>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QTableWidget;
QT_END_NAMESPACE

class CoordinateSetter : public QDialog
{
    Q_OBJECT

public:
    explicit CoordinateSetter(
            QList<QPointF> *coords, QWidget *parent = nullptr);
    virtual ~CoordinateSetter() = default;

    // [virtual public slot] from QDialog
    void done(int result) override;

private slots:
    void addRow();

private:
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;
    QList<QPointF> *coordinates;
};

#endif // COORDINATESETTER_H
