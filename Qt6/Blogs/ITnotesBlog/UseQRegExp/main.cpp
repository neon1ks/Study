#include <QCoreApplication>

#include <QDebug>
#include <QRegExp>
#include <QStringList>

void test1()
{
	QRegExp re("#include <[^>]+>");

	QStringList strings = QStringList() << "#include <iostream>"
	                                    << "    #include      <iostream>     "
	                                    << "#include \"iostream\""
	                                    << "#define <iostream>";

	for (const auto &str : strings)
	{
		qDebug() << (re.exactMatch(str) ? "matched" : "mismatched") << ":" << str;
	}

	qDebug() << "\n=================================\n";
}

void test2()
{
	static const char *const TEXT =
	    "#include <QRegExp>\n"
	    "#include <QStringList>\n"
	    "#include <QDebug>\n"
	    "\n"
	    "int main() {\n"
	    "QRegExp re( \"#include <([^>]+)>\" );\n"
	    "int lastPos = 0;\n"
	    "while( ( lastPos = re.indexIn( TEXT, lastPos ) ) != -1 ) {\n"
	    "lastPos += re.matchedLength();\n"
	    "qDebug() << re.cap( 0 );\n"
	    "}\n"
	    "return 0;\n"
	    "}";

	QRegExp re("#include <([^>]+)>");

	int lastPos = 0;
	while ((lastPos = re.indexIn(TEXT, lastPos)) != -1)
	{
		lastPos += re.matchedLength();
		qDebug() << re.cap(0) << ":" << re.cap(1);
	}

	qDebug() << "\r\n=================================\r\n";
}

void test3()
{
	static const char *const TEXT =
	    "#include <QRegExp>\n"
	    "#include <QStringList>\n"
	    "#include <QDebug>\n"
	    "\n"
	    "int main() {\n"
	    "qDebug() << QString( TEXT ).replace( QRegExp( \"#include <([^>]+)>\" ), \"#include \"\\1\"\" );\n"
	    "return 0;\n"
	    "}";

	qDebug() << QString(TEXT).replace(QRegExp("#include <([^>]+)>"), R"(#include "\1")");
}

auto main(int argc, char *argv[]) -> int
{
	QCoreApplication a(argc, argv);

	test1();
	test2();
	test3();

	return QCoreApplication::exec();
}
