#include <QtWidgets>

#include "directoryviewer.h"

DirectoryViewer::DirectoryViewer(QWidget *parent) : QDialog(parent)
{
    model = new QFileSystemModel;
    model->setReadOnly(false);
    //model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);

    treeView = new QTreeView;
    treeView->setModel(model);
    treeView->header()->setStretchLastSection(true);
    treeView->header()->setSortIndicator(0, Qt::AscendingOrder);
    treeView->header()->setSortIndicatorShown(true);
    //treeView->header()->setClickable(true);
    treeView->header()->setSectionsClickable(true);

    treeView->header()->setVisible(true);

    QModelIndex index = model->index(QDir::currentPath());
    treeView->expand(index); // Обеспечиваем просмотр содержимого каталога
    treeView->scrollTo(index); // Устанавливаем изображение на его начало

    // Обеспечиваем ширину первого столбка, достаточную для размещения
    // всех элементов без вывода многоточия (...)
    treeView->resizeColumnToContents(0);

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    QPushButton *mkdirButton = buttonBox->addButton(
            tr("&Create Directory..."), QDialogButtonBox::ActionRole);
    QPushButton *removeButton =
            buttonBox->addButton(tr("&Remove"), QDialogButtonBox::ActionRole);
    buttonBox->addButton(tr("&Quit"), QDialogButtonBox::AcceptRole);

    connect(mkdirButton, &QAbstractButton::clicked, this,
            &DirectoryViewer::createDirectory);
    connect(removeButton, &QAbstractButton::clicked, this,
            &DirectoryViewer::remove);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);

    auto *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(treeView);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

    setWindowTitle(tr("Directory Viewer"));
}

void DirectoryViewer::createDirectory()
{
    QModelIndex index = treeView->currentIndex();
    if (!index.isValid())
        return;

    QString dirName = QInputDialog::getText(
            this, tr("Create Directory"), tr("Directory name"));
    if (!dirName.isEmpty()) {
        if (!model->mkdir(index, dirName).isValid())
            QMessageBox::information(this, tr("Create Directory"),
                    tr("Failed to create the directory"));
    }
}

void DirectoryViewer::remove()
{
    QModelIndex index = treeView->currentIndex();
    if (!index.isValid())
        return;

    bool ok = {};
    if (model->fileInfo(index).isDir()) {
        ok = model->rmdir(index);
    } else {
        ok = model->remove(index);
    }
    if (!ok)
        QMessageBox::information(this, tr("Remove"),
                tr("Failed to remove %1").arg(model->fileName(index)));
}
