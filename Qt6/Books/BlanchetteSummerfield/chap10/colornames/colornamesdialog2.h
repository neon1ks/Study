#ifndef COLORNAMESDIALOG2_H
#define COLORNAMESDIALOG2_H

#include <QDialog>

class QComboBox;
class QLabel;
class QLineEdit;
class QListView;
class QSortFilterProxyModel;
class QStringListModel;

class ColorNamesDialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit ColorNamesDialog2(QWidget *parent = nullptr);
    ~ColorNamesDialog2() = default;

private slots:
    void reapplyFilter();

private:
    QStringListModel *sourceModel;
    QSortFilterProxyModel *proxyModel;
    QListView *listView;
    QLabel *filterLabel;
    QLineEdit *filterLineEdit;
};

#endif // COLORNAMESDIALOG2_H
