#include <QtCore>

void study2() {







}

int main()
{

    QList<double> list = { -1.1, 20.2, 1.1, 2.2, -2.2, 3.3, 10.1 };

    QMutableListIterator<double> im(list);
    while (im.hasNext()) {
        double val = im.next();
        if (val < 0.0) {
            im.setValue(-val);
        }
    }

    im.toFront();
    while (im.hasNext()) {
        if (im.next() < 0.0) {
            im.remove();
        }
    }
    im.toBack();
    while (im.hasPrevious()) {
        if (im.previous() > 10.0) {
            im.remove();
        }
    }

    QListIterator<double> i(list);
    while (i.hasNext()) {
        qDebug() << i.next();
    }
    qDebug() << "\n";

    i.toBack();
    while (i.hasPrevious()) {
        qDebug() << i.previous();
    }
    qDebug() << "\n";

    return 0;
}
