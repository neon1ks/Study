#ifndef SETTINGSVIEWER_H
#define SETTINGSVIEWER_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QSettings;
class QTreeWidget;
class QTreeWidgetItem;
QT_END_NAMESPACE

class SettingsViewer : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsViewer(QWidget *parent = nullptr);
    virtual ~SettingsViewer() = default;

private slots:
    // [virtual public slot] from QDialog
    void open() override;

private:
    void readSettings();
    void addChildSettings(
            QSettings &settings, QTreeWidgetItem *item, const QString &group);

    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    QString organization;
    QString application;
};

#endif // SETTINGSVIEWER_H
