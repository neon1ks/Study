#ifndef MAILCLIENT_H
#define MAILCLIENT_H

#include <QMainWindow>

class QIcon;
class QSplitter;
class QTextEdit;
class QTreeWidget;

class MailClient : public QMainWindow
{
    Q_OBJECT

public:
    MailClient(QWidget *parent = nullptr);
    ~MailClient() = default;

protected:
    void closeEvent(QCloseEvent *event);

private:
    // clang-format off
    void addFolder(const QIcon &icon, const QString &name);
    void addMessage(const QString &subject, const QString &from,
                    const QString &date);
    void readSettings();
    void writeSettings();
    // clang-format on

    QSplitter *mainSplitter;
    QSplitter *rightSplitter;
    QTreeWidget *foldersTreeWidget;
    QTreeWidget *messagesTreeWidget;
    QTextEdit *textEdit;
};
#endif // MAILCLIENT_H
