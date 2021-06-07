#include <QCoreApplication>
#include <QtCore>

int run1()
{
    QFile file;
    file.setFileName(R"(C:\Qt\Docs\Qt-5.15.2\classes.txt)");
    // file.setFileName("C:\\Qt\\Docs\\Qt-5.15.2\\classes.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << QObject::tr("Ошибка открытия для чтения");
        return -1;
    }

    QTextStream in(&file);

    QRegularExpression re1("<!-- @@@([^>]+) -->");
    QRegularExpression re2("This class was introduced in Qt ([^>]+).</p>");
    bool findClass = true;

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (findClass) {
            auto match = re1.match(line);
            if (match.hasMatch()) {
                qDebug() << match.captured(1);
                findClass = false;
            }
        } else {
            auto match2 = re2.match(line);
            if (match2.hasMatch()) {
                qDebug() << match2.captured(1);
                findClass = true;
            }
        }
    }
    file.close();
    return 0;
}

int run2()
{
    bool isQt6 = false;

    QFile inputFile;
    QFile outputFile;
    inputFile.setFileName(R"(C:\Qt\Docs\Qt6inherits.txt)");
    outputFile.setFileName(R"(C:\Qt\Docs\Qt6AllClasses.txt)");

    // inputFile.setFileName(R"(C:\Qt\Docs\Qt5inherits.txt)");
    // outputFile.setFileName(R"(C:\Qt\Docs\Qt5Allclasses.txt)");

    if (!inputFile.open(QIODevice::ReadOnly)) {
        qDebug() << QObject::tr("Ошибка открытия для чтения");
        return -1;
    }

    if (!outputFile.open(QIODevice::WriteOnly)) {
        qDebug() << QObject::tr("Ошибка открытия для записи");
        return -1;
    }

    QTextStream in(&inputFile);
    QTextStream out(&outputFile);

    QRegularExpression re1("<!-- @@@([^>]+) -->");
    QRegularExpression re2b("Since:");
    QRegularExpression re2c("Instantiated");
    QRegularExpression re2d("Instantiates:");
    QRegularExpression re2e("Inherits:");
    QRegularExpression re2f("Inherited");
    QRegularExpression re2g("qmake:");

    QRegularExpression re3("cmake:");
    QRegularExpression re4a("qmake:");
    QRegularExpression re4b("Import Statement:");

    QRegularExpression re6("Since:");
    QRegularExpression re7("Instantiated By:");
    QRegularExpression re8("Instantiates:");
    QRegularExpression re9("Inherits:");
    QRegularExpression re10("Inherited By:");

    QRegularExpression reEnd("<ul>");
    QRegularExpression reEnd2("<p>");

    bool findClass = true;
    bool isCpp = false;

    //    int iLine = 0;

    QString tempString1;
    QString tempString2;

    bool isFound = false;
    int addedLine = -1;

    bool foundUl = false;

    while (!in.atEnd()) {
        QString line = in.readLine();

        foundUl = false;
        auto matchEnd = reEnd.match(line);
        if (matchEnd.hasMatch()) {
            foundUl = true;
        }

        if (findClass) {
            auto match = re1.match(line);
            if (match.hasMatch()) {
                //                qDebug() << match.captured(1);
                // out << match.captured(1) << "\t";
                tempString1 = match.captured(1);
                findClass = false;
            }
        } else {
            auto match2b = re2b.match(line);
            auto match2c = re2c.match(line);
            auto match2d = re2d.match(line);
            auto match2e = re2e.match(line);
            auto match2f = re2f.match(line);
            auto match2g = re2g.match(line);
            isFound = false;
            if (match2b.hasMatch()) {
                isFound = true;
            } else if (match2c.hasMatch()) {
                isFound = true;
            } else if (match2d.hasMatch()) {
                isFound = true;
            } else if (match2e.hasMatch()) {
                isFound = true;
            } else if (match2f.hasMatch()) {
                isFound = true;
            } else if (match2g.hasMatch()) {
                isFound = true;
            }
            if (isFound) {
                addedLine = 0;
                line.replace("<tr>", "\t");
                line.replace("<p>", "\t");
                line.remove(QRegularExpression("^[^\t]*\t"));
                line.remove(QRegularExpression("<[^>]*>"));
                line = line.mid(1);
                line.replace("\t ", "\t");
                line.replace(" \t", "\t");
                line.replace("Inherited By:\t", "Inherited By: ");
                line.replace("Inherits:\t", "Inherits: ");

                if (isQt6) {
                    auto match3 = re3.match(line);
                    if (!match3.hasMatch()) {
                        line.insert(0, QString("cmake: None\t"));
                    }
                }

                auto match4a = re4a.match(line);
                if (!match4a.hasMatch()) {
                    auto match4b = re4b.match(line);
                    if (!match4b.hasMatch()) {
                        int j = 0;
                        if (isQt6) {
                            j = line.indexOf("\t", j) + 1;
                        }
                        line.insert(j, QString("qmake: None\t"));
                        isCpp = true;
                    } else {
                        isCpp = false;
                    }
                } else {
                    isCpp = true;
                }

                auto match6 = re6.match(line);
                if (!match6.hasMatch()) {
                    int j = line.indexOf("\t", 0);
                    if (isQt6) {
                        j = line.indexOf("\t", j + 1);
                    }
                    if (j < 0) {
                        line += QString("\tSince: None");
                    } else {
                        line.insert(j + 1, QString("Since: None\t"));
                    }
                }
                auto match7 = re7.match(line);
                if (!match7.hasMatch()) {
                    int j = line.indexOf("\t", 0);
                    j = line.indexOf("\t", j + 1);
                    if (isQt6) {
                        j = line.indexOf("\t", j + 1);
                    }
                    if (j < 0) {
                        line += QString("\tInstantiated By: None");
                    } else {
                        line.insert(j + 1, QString("Instantiated By: None\t"));
                    }
                }
                auto match8 = re8.match(line);
                if (!match8.hasMatch()) {
                    int j = line.indexOf("\t", 0);
                    j = line.indexOf("\t", j + 1);
                    j = line.indexOf("\t", j + 1);
                    if (isQt6) {
                        j = line.indexOf("\t", j + 1);
                    }
                    if (j < 0) {
                        line += QString("\tInstantiates: None");
                    } else {
                        line.insert(j + 1, QString("Instantiates: None\t"));
                    }
                }
                auto match9 = re9.match(line);
                if (!match9.hasMatch()) {
                    int j = line.indexOf("\t", 0);
                    j = line.indexOf("\t", j + 1);
                    j = line.indexOf("\t", j + 1);
                    j = line.indexOf("\t", j + 1);
                    if (isQt6) {
                        j = line.indexOf("\t", j + 1);
                    }
                    if (j < 0) {
                        line += QString("\tInherits: None");
                    } else {
                        line.insert(j + 1, QString("Inherits: None\t"));
                    }
                }
                auto match10 = re10.match(line);
                if (!match10.hasMatch()) {
                    int j = line.indexOf("\t", 0);
                    j = line.indexOf("\t", j + 1);
                    j = line.indexOf("\t", j + 1);
                    j = line.indexOf("\t", j + 1);
                    j = line.indexOf("\t", j + 1);
                    if (isQt6) {
                        j = line.indexOf("\t", j + 1);
                    }
                    if (j < 0) {
                        line += QString("\tInherited By: None");
                    } else {
                        line.insert(j + 1, QString("Inherited By: None\t"));
                    }
                }
                int jj{};
                int countTab = 0;
                while ((jj = line.indexOf("\t", jj)) != -1) {
                    ++countTab;
                    ++jj;
                }
                if (countTab == 5) {
                    line += QString("\t");
                }
                //                qDebug() << line;
                if (isCpp) {

                    line.replace("5.0\t", "5.00\t");
                    line.replace("5.1\t", "5.01\t");
                    line.replace("5.2\t", "5.02\t");
                    line.replace("5.3\t", "5.03\t");
                    line.replace("5.4\t", "5.04\t");
                    line.replace("5.5\t", "5.05\t");
                    line.replace("5.6\t", "5.06\t");
                    line.replace("5.7\t", "5.07\t");
                    line.replace("5.8\t", "5.08\t");
                    line.replace("5.9\t", "5.09\t");

                    line.replace("4.0\t", "4.00\t");
                    line.replace("4.1\t", "4.01\t");
                    line.replace("4.2\t", "4.02\t");
                    line.replace("4.2)\t", "4.02\t");
                    line.replace("4.3\t", "4.03\t");
                    line.replace("4.4\t", "4.04\t");
                    line.replace("4.5\t", "4.05\t");
                    line.replace("4.6\t", "4.06\t");
                    line.replace("4.7\t", "4.07\t");
                    line.replace("4.8\t", "4.08\t");
                    line.replace("4.9\t", "4.09\t");

                    tempString2 = line;
                }

                findClass = true;
            }
        }

        if (addedLine > 0) {
            auto matchEnd2 = reEnd2.match(line);
            if (matchEnd2.hasMatch()) {
                line.replace("<p>", "\t");
                line.remove(QRegularExpression("^[^\t]*\t"));
                line.remove(QRegularExpression("<[^>]*>"));

                auto l = tempString2.length();
                if (tempString2[l - 1] == QChar('\t')
                        || tempString2[l - 1] == QChar(' ')) {
                    tempString2 += line;
                } else {
                    tempString2 += QString(" ") + line;
                }
            }

            if (foundUl) {
                auto l = tempString2.length();
                if (tempString2[l - 1] == QChar('\t')) {
                    tempString2 += QString("None");
                }

                out << tempString1 + "\t";
                out << tempString2 << "\r\n";
                addedLine = -1;
                findClass = true;
            } else {
                ++addedLine;
            }
        }

        if (addedLine == 0) {
            if (foundUl) {
                auto l = tempString2.length();
                if (tempString2[l - 1] == QChar('\t')) {
                    tempString2 += QString("None");
                }
                out << tempString1 + "\t";
                out << tempString2 << "\r\n";
                findClass = true;
                addedLine = -1;
            } else {
                ++addedLine;
            }
        }
        //        ++iLine;
        //        if (iLine == 100) {
        //            break;
        //        }
    }
    inputFile.close();
    outputFile.close();
    qDebug() << "End";
    return 0;
}

int run3()
{
    QFile inputFile;
    QFile outputFile;
    inputFile.setFileName(R"(C:\Qt\Docs\Qt-6.1.0\inheritsCpp2.txt)");
    outputFile.setFileName(R"(C:\Qt\Docs\Qt-6.1.0\inheritsCpp3.txt)");

    if (!inputFile.open(QIODevice::ReadOnly)) {
        qDebug() << QObject::tr("Ошибка открытия для чтения");
        return -1;
    }

    if (!outputFile.open(QIODevice::WriteOnly)) {
        qDebug() << QObject::tr("Ошибка открытия для записи");
        return -1;
    }

    QTextStream in(&inputFile);
    QTextStream out(&outputFile);

    QString lineOdd = in.readLine();
    out << lineOdd << "\r\n";
    QString lineEven;
    // bool odd;      // нечетный
    bool even = true; // четный

    while (!in.atEnd()) {
        if (even) {
            lineEven = in.readLine();
        } else {
            lineOdd = in.readLine();
        }

        if (lineEven != lineOdd) {
            if (even) {
                out << lineEven << "\r\n";
            } else {
                out << lineOdd << "\r\n";
            }
        }

        even = !even;
    }
    inputFile.close();
    outputFile.close();
    qDebug() << "End";
    return 0;
}

int main()
{
    run2();
    return 0;
}
