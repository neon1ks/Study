#include <QtWidgets>

#include "coordinatesetter.h"

CoordinateSetter::CoordinateSetter(QList<QPointF> *coords, QWidget *parent)
    : QDialog(parent)
{

    coordinates = coords;

    tableWidget = new QTableWidget(0, 2);

    // Запретить редактирование ячеек:
    // tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setHorizontalHeaderLabels(QStringList() << tr("X") << tr("Y"));

    for (int row = 0; row < coordinates->count(); ++row) {
        QPointF point = coordinates->at(row);
        addRow();
        tableWidget->item(row, 0)->setText(QString::number(point.x()));
        tableWidget->item(row, 1)->setText(QString::number(point.y()));
    }

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    QPushButton *addRowButton =
            buttonBox->addButton(tr("&Add Row"), QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(addRowButton, &QAbstractButton::clicked, this,
            &CoordinateSetter::addRow);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(tableWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Coordinate Setter"));
}

void CoordinateSetter::done(int result)
{
    if (result == QDialog::Accepted) {
        coordinates->clear();
        for (int row = 0; row < tableWidget->rowCount(); ++row) {
            double x = tableWidget->item(row, 0)->text().toDouble();
            double y = tableWidget->item(row, 1)->text().toDouble();
            coordinates->append(QPointF(x, y));
        }
    }
    QDialog::done(result);
}

void CoordinateSetter::addRow()
{
    int row = tableWidget->rowCount();

    tableWidget->insertRow(row);

    auto *item0 = new QTableWidgetItem;
    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tableWidget->setItem(row, 0, item0);

    auto *item1 = new QTableWidgetItem;
    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    tableWidget->setItem(row, 1, item1);

    tableWidget->setCurrentItem(item0);
}
