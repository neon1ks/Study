#include <QCoreApplication>
#include <QDebug>
#include <QRegularExpression>

static const QStringList STRINGS = {
    "#include <iostream>",
    "before\n#include <iostream>\nafter",
    " #include <iostream> ",
    "#include <",
    "    #include      <iostream>     ",
    "#include \"iostream\"",
    "#define <iostream>"
};

static const char *const TEXT =
    "#include <QDebug>\n"
    "#include <QRegularExpression>\n"
    "\n"
    "int main() {\n"
    "QRegularExpression re( \"#include <([^>]+)>\" );\n"
    "auto it = re.globalMatch( TEXT );\n"
    "while( it.hasNext() ) {\n"
    "auto match = it.next();\n"
    "qDebug() << match.captured( 0 ) << \":\" << match.captured( 1 );\n"
    "}\n"
    "return 0;\n"
    "}";

// **********************************************************************
void runMatchingTest(const QRegularExpression &re)
{
	for (const auto &str : STRINGS)
	{
		auto match = re.match(str);
		qDebug() << (match.hasMatch() ? QString("   matched") : QString("mismatched")) << ":" << str;
	}
}

// **********************************************************************
void normalMatchingTest()
{
	QRegularExpression re("#include <[^>]+>");
	runMatchingTest(re);
}

// **********************************************************************
void exactMatchingTest()
{
	QRegularExpression re("^#include <[^>]+>$");
	runMatchingTest(re);
}

// **********************************************************************
void multilneExactMatchingTest()
{
	QRegularExpression re("^#include <[^>]+>$", QRegularExpression::MultilineOption);
	runMatchingTest(re);
}

// **********************************************************************
void partialMatchingTest()
{
	QRegularExpression re("^#include <[^>]+>$");

	for (const auto &str : STRINGS)
	{
		auto match = re.match(str, 0, QRegularExpression::PartialPreferCompleteMatch);
		qDebug() << (match.hasPartialMatch() ? QString("partially matched") : QString("       mismatched")) << ":" << str;
	}
}

// **********************************************************************
void globalMatchingTest()
{
	QRegularExpression re("#include <([^>]+)>");

	auto it = re.globalMatch(TEXT);
	while (it.hasNext())
	{
		auto match = it.next();
		qDebug() << match.captured(0) << ":" << match.captured(1);
	}
}

// **********************************************************************
void replacingTest()
{
	QRegularExpression re("#include <([^>]+)>");

	qDebug() << qPrintable(QString(TEXT).replace(re, "#include \"\\1\""));
}

// **********************************************************************
template <typename Func>
void runTest(const char *name, Func func)
{
	qDebug() << "**************************************************";
	qDebug() << name;
	qDebug() << "";
	func();
	qDebug() << "";
}

// **********************************************************************
auto main(int argc, char *argv[]) -> int
{
	QCoreApplication a(argc, argv);

	runTest("Normal Matching", normalMatchingTest);
	runTest("Exact Matching", exactMatchingTest);
	runTest("Multiline Exact Matching", multilneExactMatchingTest);
	runTest("Partial Matching", partialMatchingTest);
	runTest("Global Matching", globalMatchingTest);
	runTest("Replacing", replacingTest);

	return QCoreApplication::exec();
}
