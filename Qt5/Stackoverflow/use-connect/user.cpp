#include "user.h"

User::User(QObject *parent) : QObject(parent)
{
    age_ = 0;
    counter++;
    id_ = new int(counter);
}

User::~User()
{
    delete id_;
}

QString User::getName() const
{
    return name_;
}

QString User::getPassword() const
{
    return password_;
}

int User::getAge() const
{
    return age_;
}

void User::setName(const QString &name)
{
    name_ = name;
}
void User::setPassword(const QString &password)
{
    password_ = password;
}
void User::setAge(int age)
{
    age_ = age;
}

int User::counter = 0;
