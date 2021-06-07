#include <QStringView>
#include <QString>
#include <QDebug>

#include <array>
#include <stdexcept>

// Выделение части строки
void test1()
{
    // void chop(qsizetype length)
    // void truncate(qsizetype length)

    // QStringView chopped(qsizetype length) const
    // QStringView first(qsizetype n) const
    // QStringView last(qsizetype n) const
    // QStringView sliced(qsizetype pos, qsizetype n) const
    // QStringView sliced(qsizetype pos) const
    // QStringView trimmed() const
}

// Получение символа строки
void test2()
{

    // QChar at(qsizetype n) const
    // QChar back() const
    // QChar first() const
    // QChar front() const
    // QChar last() const
    // QChar operator[](qsizetype n) const
}

// Условия
void test3()
{
    // bool contains(QChar c, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool contains(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool contains(QLatin1String l1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool contains(const QRegularExpression &re, QRegularExpressionMatch *rmatch = nullptr) const
    // bool empty() const
    // bool endsWith(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool endsWith(QLatin1String l1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool endsWith(QChar ch) const
    // bool endsWith(QChar ch, Qt::CaseSensitivity cs) const
    // bool isEmpty() const
    // bool isNull() const
    // bool isRightToLeft() const
    // bool isValidUtf16() const
    // bool startsWith(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool startsWith(QLatin1String l1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // bool startsWith(QChar ch) const
    // bool startsWith(QChar ch, Qt::CaseSensitivity cs) const
}

// Конвертирование
void test4()
{
    // CFStringRef toCFString() const
    // double      toDouble(bool *ok = nullptr) const
    // float       toFloat(bool *ok = nullptr) const
    // int         toInt(bool *ok = nullptr, int base = 10) const
    // QByteArray  toLatin1() const
    // QByteArray  toLocal8Bit() const
    // long        toLong(bool *ok = nullptr, int base = 10) const
    // qlonglong   toLongLong(bool *ok = nullptr, int base = 10) const
    // NSString *  toNSString() const
    // short       toShort(bool *ok = nullptr, int base = 10) const
    // QString     toString() const
    // uint        toUInt(bool *ok = nullptr, int base = 10) const
    // ulong       toULong(bool *ok = nullptr, int base = 10) const
    // qulonglong  toULongLong(bool *ok = nullptr, int base = 10) const
    // ushort      toUShort(bool *ok = nullptr, int base = 10) const
    // QList<uint> toUcs4() const
    // QByteArray  toUtf8() const
    // qsizetype   toWCharArray(wchar_t *array) const
}

// Получение количества элементов или позиции подстроки
void test5()
{
    //int length() const

    // qsizetype count(const QRegularExpression &re) const
    // qsizetype count(QChar ch, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype count(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype indexOf(QChar c, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype indexOf(QStringView str, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype indexOf(QLatin1String l1, qsizetype from = 0, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype indexOf(const QRegularExpression &re, qsizetype from = 0, QRegularExpressionMatch *rmatch = nullptr) const
    // qsizetype lastIndexOf(QChar c, qsizetype from = -1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype lastIndexOf(QStringView str, qsizetype from = -1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype lastIndexOf(QLatin1String l1, qsizetype from = -1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // qsizetype lastIndexOf(const QRegularExpression &re, qsizetype from = -1, QRegularExpressionMatch *rmatch = nullptr) const
    // qsizetype size() const
}

// Сравнение
void test6()
{
    // int compare(QStringView str, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // int compare(QLatin1String l1, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // int compare(QChar ch) const
    // int compare(QChar ch, Qt::CaseSensitivity cs) const
}

void test7()
{
    // QStringView::const_iterator begin() const
    // QStringView::const_iterator cbegin() const
    // QStringView::const_iterator cend() const
    // QStringView::const_iterator constBegin() const
    // QStringView::const_iterator constEnd() const
    // QStringView::const_iterator end() const

    // QStringView::const_reverse_iterator crbegin() const
    // QStringView::const_reverse_iterator crend() const
    // QStringView::const_reverse_iterator rbegin() const
    // QStringView::const_reverse_iterator rend() const
}

void test8()
{
    // QList<QStringView> split(QStringView sep, Qt::SplitBehavior behavior = Qt::KeepEmptyParts, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // QList<QStringView> split(QChar sep, Qt::SplitBehavior behavior = Qt::KeepEmptyParts, Qt::CaseSensitivity cs = Qt::CaseSensitive) const
    // QList<QStringView> split(const QRegularExpression &re, Qt::SplitBehavior behavior = Qt::KeepEmptyParts) const
}
void test9()
{
    // decltype(qTokenize(*this, std::forward<Needle>(needle), flags...)) tokenize(Needle &&sep, Flags... flags) const

    // QStringView::const_pointer constData() const
    // QStringView::const_pointer data() const

    // QString arg(Args &&... args) const
}

int main()
{

    QString str1 = "test1";
    QString str2 = "test2";

    QStringView strView1 = str1;
    QStringView strView2 = str2;

    if (strView1 == strView2) {
        qDebug() << "compare";
    }

    try {
        qDebug() << strView1.at(3);
    } catch (...) {
        qDebug() << "good";
    }

    std::array<int, 5> arr = { 1, 2, 3, 4, 5 };

    try {
        qDebug() << arr.at(10);
    } catch (std::out_of_range &orr) {
        qDebug() << "Out of Range error:" << orr.what();
    }

    return 0;
}
