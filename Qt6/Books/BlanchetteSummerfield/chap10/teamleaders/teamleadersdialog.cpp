#include <QtWidgets>

#include "teamleadersdialog.h"

TeamLeadersDialog::TeamLeadersDialog(
        const QStringList &leaders, QWidget *parent)
    : QDialog(parent)
{
    model = new QStringListModel(this);
    model->setStringList(leaders);

    listView = new QListView;
    listView->setModel(model);

    // Разрешаем пользователю редактировать строку, просто вводя символ
    // или делая двойной щелчок
    listView->setEditTriggers(QAbstractItemView::AnyKeyPressed
                              | QAbstractItemView::DoubleClicked);

    buttonBox = new QDialogButtonBox();
    QPushButton *insertButton =
            buttonBox->addButton(tr("&Insert"), QDialogButtonBox::ActionRole);
    QPushButton *deleteButton =
            buttonBox->addButton(tr("&Delete"), QDialogButtonBox::ActionRole);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);

    connect(insertButton, &QAbstractButton::clicked, this,
            &TeamLeadersDialog::insert);
    connect(deleteButton, &QAbstractButton::clicked, this,
            &TeamLeadersDialog::del);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(listView);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Team Leaders"));
}

QStringList TeamLeadersDialog::leaders() const
{
    return model->stringList();
}

void TeamLeadersDialog::insert()
{
    int row = listView->currentIndex().row();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);
    listView->setCurrentIndex(index);
    listView->edit(index);
}

void TeamLeadersDialog::del()
{
    model->removeRows(listView->currentIndex().row(), 1);
}
