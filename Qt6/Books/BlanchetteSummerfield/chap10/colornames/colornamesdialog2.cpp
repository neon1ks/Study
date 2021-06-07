#include <QtWidgets>

#include "colornamesdialog2.h"

ColorNamesDialog2::ColorNamesDialog2(QWidget *parent) : QDialog(parent)
{
    sourceModel = new QStringListModel(this);
    sourceModel->setStringList(QColor::colorNames());

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterKeyColumn(0);

    listView = new QListView;
    listView->setModel(proxyModel);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    filterLabel = new QLabel(tr("&Filter:"));
    filterLineEdit = new QLineEdit;
    filterLabel->setBuddy(filterLineEdit);

    // clang-format off
    connect(filterLineEdit, &QLineEdit::textChanged,
            this, &ColorNamesDialog2::reapplyFilter);
    // clang-format on

    auto *mainLayout = new QGridLayout;
    mainLayout->addWidget(listView, 0, 0, 1, 2);
    mainLayout->addWidget(filterLabel, 1, 0);
    mainLayout->addWidget(filterLineEdit, 1, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("Color Names"));
}

void ColorNamesDialog2::reapplyFilter()
{
    QRegularExpression regExp(
            filterLineEdit->text(), QRegularExpression::CaseInsensitiveOption);
    proxyModel->setFilterRegularExpression(regExp);
}
