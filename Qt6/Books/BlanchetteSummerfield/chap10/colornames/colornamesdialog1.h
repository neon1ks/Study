#ifndef COLORNAMESDIALOG1_H
#define COLORNAMESDIALOG1_H

#include <QDialog>

class QComboBox;
class QLabel;
class QLineEdit;
class QListView;
class QSortFilterProxyModel;
class QStringListModel;

class ColorNamesDialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit ColorNamesDialog1(QWidget *parent = nullptr);
    ~ColorNamesDialog1() = default;

private slots:
    void reapplyFilter();

private:
    QStringListModel *sourceModel;
    QSortFilterProxyModel *proxyModel;
    QListView *listView;
    QLabel *filterLabel;
    QLabel *syntaxLabel;
    QLineEdit *filterLineEdit;
    QComboBox *syntaxComboBox;
};

#endif // COLORNAMESDIALOG_H
