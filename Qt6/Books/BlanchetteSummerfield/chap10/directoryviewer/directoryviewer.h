#ifndef DIRECTORYVIEWER_H
#define DIRECTORYVIEWER_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QFileSystemModel;
class QTreeView;
QT_END_NAMESPACE

class DirectoryViewer : public QDialog
{
    Q_OBJECT

public:
    explicit DirectoryViewer(QWidget *parent = nullptr);
    virtual ~DirectoryViewer() = default;

private slots:
    void createDirectory();
    void remove();

private:
    QTreeView *treeView;
    QFileSystemModel *model;
    QDialogButtonBox *buttonBox;
};

#endif // DIRECTORYVIEWER_H
