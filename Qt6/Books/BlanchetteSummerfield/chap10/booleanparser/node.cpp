#include <QtCore>

#include "booleanparser.h"

Node::Node(Type type, const QString &str)
{
    this->type = type;
    this->str = str;
    parent = nullptr;
}

Node::~Node()
{
    // Функция `qDeleteAll()` проходит по всем указателям контейнера и вызывает
    // оператор delete для каждого из них. Она не устанавливает уазатели в
    // пустое значение, поэтому, если она используется вне деструктора,
    // обычно за ней следует вызов фукнции `clear()` для контейнера,
    // содержащего указатели.
    qDeleteAll(children);
}
