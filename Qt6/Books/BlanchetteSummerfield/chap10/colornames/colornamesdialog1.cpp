#include <QtWidgets>

#include "colornamesdialog1.h"

ColorNamesDialog1::ColorNamesDialog1(QWidget *parent) : QDialog(parent)
{
    sourceModel = new QStringListModel(this);
    sourceModel->setStringList(QColor::colorNames());

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterKeyColumn(0);

    listView = new QListView;
    listView->setModel(proxyModel);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    filterLabel = new QLabel(tr("&Filter:"));
    filterLineEdit = new QLineEdit;
    filterLabel->setBuddy(filterLineEdit);

    syntaxLabel = new QLabel(tr("&Pattern syntax:"));
    syntaxComboBox = new QComboBox;
    syntaxComboBox->addItem(tr("Regular expression"), QRegExp::RegExp);
    syntaxComboBox->addItem(tr("Wildcard"), QRegExp::Wildcard);
    syntaxComboBox->addItem(tr("Fixed string"), QRegExp::FixedString);
    syntaxLabel->setBuddy(syntaxComboBox);

    // clang-format off
    connect(filterLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(reapplyFilter()));
    connect(syntaxComboBox, SIGNAL(currentIndexChanged(int)),
            this, SLOT(reapplyFilter()));
    // clang-format on
#endif

    auto *mainLayout = new QGridLayout;
    mainLayout->addWidget(listView, 0, 0, 1, 2);
    mainLayout->addWidget(filterLabel, 1, 0);
    mainLayout->addWidget(filterLineEdit, 1, 1);
    mainLayout->addWidget(syntaxLabel, 2, 0);
    mainLayout->addWidget(syntaxComboBox, 2, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("Color Names"));
}

void ColorNamesDialog1::reapplyFilter()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(
            syntaxComboBox->itemData(syntaxComboBox->currentIndex()).toInt());
    QRegExp regExp(filterLineEdit->text(), Qt::CaseInsensitive, syntax);
    proxyModel->setFilterRegExp(regExp);
#endif
}
