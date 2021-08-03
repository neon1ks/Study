#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT
public:
    static int counter;

    explicit User(QObject *parent = nullptr);
    ~User();
    QString getName() const;
    QString getPassword() const;
    int getAge() const;
public slots:
    void setName(const QString &name);
    void setPassword(const QString &password);
    void setAge(int age);

protected:
    QString name_;
    QString password_;
    int *id_;
    int age_;
};

#endif // USER_H
