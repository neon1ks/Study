#ifndef TEAMLEADERSDIALOG_H
#define TEAMLEADERSDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QListView;
class QStringListModel;
QT_END_NAMESPACE

class TeamLeadersDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TeamLeadersDialog(
            const QStringList &leaders, QWidget *parent = nullptr);
    virtual ~TeamLeadersDialog() = default;

    QStringList leaders() const;

private slots:
    void insert();
    void del();

private:
    QListView *listView;
    QDialogButtonBox *buttonBox;
    QStringListModel *model;
};

#endif // TEAMLEADERSDIALOG_H
