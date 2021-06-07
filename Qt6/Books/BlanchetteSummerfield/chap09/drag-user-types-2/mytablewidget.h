#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QWidget>
#include <QTableWidget>

class MyTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    MyTableWidget(QWidget *parent = nullptr);
    ~MyTableWidget() = default;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dropEvent(QDropEvent *event);

private:
    enum { MagicNumber = 0x7F51C883, RowCount = 999, ColumnCount = 26 };

    void clear();
    void performDrag();
    // QString toCsv(const QString &plainText);
    // QString toHtml(const QString &plainText);

    QPoint startPos;
};
#endif // MYTABLEWIDGET_H
