#include <QtWidgets>

#include "settingsviewer.h"

SettingsViewer::SettingsViewer(QWidget *parent) : QDialog(parent)
{
    organization = "QtProject";
    application = "Designer";

    treeWidget = new QTreeWidget;
    treeWidget->setColumnCount(2);
    treeWidget->setHeaderLabels(QStringList() << tr("Key") << tr("Value"));
    treeWidget->header()->setSectionResizeMode(0, QHeaderView::Stretch);
    treeWidget->header()->setSectionResizeMode(1, QHeaderView::Stretch);

    buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Open | QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::accepted, this,
            &SettingsViewer::open);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QWidget::close);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(treeWidget);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Settings Viewer"));
    readSettings();
}

void SettingsViewer::open()
{
    QDialog dialog(this);

    auto *orgLabel = new QLabel(tr("&Organization:"));
    auto *orgLineEdit = new QLineEdit(organization);
    orgLabel->setBuddy(orgLineEdit);

    auto *appLabel = new QLabel(tr("&Application:"));
    auto *appLineEdit = new QLineEdit(application);
    appLabel->setBuddy(appLineEdit);

    auto *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    auto *gridLayout = new QGridLayout;
    gridLayout->addWidget(orgLabel, 0, 0);
    gridLayout->addWidget(orgLineEdit, 0, 1);
    gridLayout->addWidget(appLabel, 1, 0);
    gridLayout->addWidget(appLineEdit, 1, 1);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gridLayout);
    mainLayout->addWidget(buttonBox);
    dialog.setLayout(mainLayout);

    dialog.setWindowTitle(tr("Choose Settings"));

    if (dialog.exec()) {
        organization = orgLineEdit->text();
        application = appLineEdit->text();
        readSettings();
    }
}

void SettingsViewer::readSettings()
{
    QSettings settings(organization, application);

    treeWidget->clear();
    addChildSettings(settings, nullptr, "");

    treeWidget->sortByColumn(0, Qt::AscendingOrder);
    treeWidget->setFocus();
    setWindowTitle(
            tr("Settings Viewer - %1 by %2").arg(application, organization));
}

void SettingsViewer::addChildSettings(
        QSettings &settings, QTreeWidgetItem *parent, const QString &group)
{
    if (!parent)
        parent = treeWidget->invisibleRootItem();
    QTreeWidgetItem *item = nullptr;

    settings.beginGroup(group);

    for (const QString &key : settings.childKeys()) {
        item = new QTreeWidgetItem(parent);
        item->setText(0, key);
        if (settings.value(key).metaType().id() == QMetaType::QByteArray) {
            item->setText(1, QString("Binary"));
        } else if (settings.value(key).canConvert<QString>()) {
            item->setText(1, settings.value(key).toString());
        } else {
            item->setText(1, QString("Other"));
        }
    }
    for (const QString &group : settings.childGroups()) {
        item = new QTreeWidgetItem(parent);
        item->setText(0, group);
        addChildSettings(settings, item, group);
    }
    settings.endGroup();
}
