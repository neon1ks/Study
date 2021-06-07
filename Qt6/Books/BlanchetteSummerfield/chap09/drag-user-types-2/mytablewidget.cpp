#include "mytablewidget.h"
#include "tablemimedata.h"

#include <QtWidgets>

MyTableWidget::MyTableWidget(QWidget *parent) : QTableWidget(parent)
{
    setAcceptDrops(true);
    setSelectionMode(ContiguousSelection);

    clear(); // Для изменения размеров таблицы и задания заголовкой столбцов
}

void MyTableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        startPos = event->pos();
    QTableWidget::mousePressEvent(event);
}

void MyTableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance()) {
            performDrag();
        }
    }
    QTableWidget::mouseMoveEvent(event);
}

void MyTableWidget::dropEvent(QDropEvent *event)
{
    const TableMimeData *tableData =
            qobject_cast<const TableMimeData *>(event->mimeData());

    if (tableData) {
        const QTableView *otherTable = tableData->tableWidget();
        QTableWidgetSelectionRange otherRange = tableData->range();

        // ...
        event->acceptProposedAction();
    }

    if (event->mimeData()->hasFormat("text/csv")) {
        QByteArray csvData = event->mimeData()->data("text/csv");
        QString csvText = QString::fromUtf8(csvData);
        // ...
        event->acceptProposedAction();
    } else if (event->mimeData()->hasFormat("text/plain")) {
        QString plainText = event->mimeData()->text();
        // ...
        event->acceptProposedAction();
    }
    // QTableWidget::mouseMoveEvent(event);
}

void MyTableWidget::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; ++i) {
        auto *item = new QTableWidgetItem;
        item->setText(QString(QChar('A' + i)));
        setHorizontalHeaderItem(i, item);
    }

    setCurrentCell(0, 0);
}

/*
void MyTableWidget::performDrag()
{
    QString plainText{ "TODO" }; // = selectionAsPlainText();
    if (plainText.isEmpty()) {
        return;
    }

    auto *mimeData = new QMimeData;
    mimeData->setText(plainText);
    mimeData->setHtml(toHtml(plainText));
    mimeData->setData("text/csv", toCsv(plainText).toUtf8());

    auto *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if (drag->exec(Qt::CopyAction | Qt::MoveAction) == Qt::MoveAction) {
        // deleteSelection();
    }
}
*/
