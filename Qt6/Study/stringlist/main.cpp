#include <QStringList>
#include <QDebug>

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QString one = "one;";
    QString two = "two";
    QString three = "three";

    QStringList listOne;

    listOne << one;
    listOne << two;
    listOne << three;

    qDebug() << listOne;

    QStringList listTwo;

    listTwo += one;
    listTwo += two;
    listTwo += three;

    qDebug() << listTwo;

    QStringList listThree;

    listThree.append(one);
    listThree.append(two);
    listThree.append(three);

    qDebug() << listThree;

    return 0;
}
