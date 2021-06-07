#include "spell_text_edit.h"

#include <QCompleter>
//#include <QTextCodec>
#include <QAction>
#include <QMenu>
#include "hunspell/hunspell.hxx"
#include <QDebug>
#include <QRegularExpression>

#include <fstream>

const std::string file_name_dic = {
    "C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/ru_RU/ru_RU.dic"
};
const std::string file_name_aff = {
    "C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/ru_RU/ru_RU.aff"
};

SpellDictionary::SpellDictionary(const std::string &aff, const std::string &dic)
    : dict(nuspell::Dictionary())
{
    std::ifstream file_aff;
    std::ifstream file_dic;

    file_aff.open(aff);
    file_dic.open(dic);

    if (file_aff.is_open() && file_dic.is_open()) {
        try {

            dict = nuspell::Dictionary::load_from_aff_dic(file_aff, file_dic);
            qDebug() << "Dict load";
        } catch (const nuspell::Dictionary_Loading_Error &e) {
            dict = nuspell::Dictionary();
        }
    }
    if (file_aff.is_open()) {
        file_aff.close();
    }
    if (file_dic.is_open()) {
        file_dic.close();
    }
}

bool SpellDictionary::spell(QStringView word)
{
    if (isRussian(word)) {
        std::string w = word.toUtf8().constData();
        return dict.spell(w);
    }
    return true;
}

void SpellDictionary::suggest(const QString &word, QStringList &out)
{
    std::string w = word.toUtf8().constData();
    std::vector<std::string> suggestions;

    try {
        // Encode from Unicode to the encoding used by current dictionary
        dict.suggest(w, suggestions);

        for (const auto &s : suggestions) {
            out << QString::fromStdString(s);
        }
    } catch (...) {
        qDebug() << "Error keyword";
    }
}

bool SpellDictionary::isRussian(QStringView word)
{
    for (const auto &ch : word) {
        if (ch.unicode() < u'Ё' || u'ё' < ch.unicode()) {
            return false;
        }
    }
    return true;
}

void SpellDictionary::test(const QString &word)
{
    std::string w = word.toUtf8().constData();
    if (dict.spell(w)) {
        qDebug() << "Word \"" << word << "\" is ok.\n";
        return;
    }
    auto sugs = std::vector<std::string>();
    qDebug() << "Word \"" << word << "\" is incorrect.\n";
    dict.suggest(w, sugs);
    if (sugs.empty()) {
        return;
    }
    qDebug() << "  Suggestions are: ";
    for (auto &sug : sugs) {
        qDebug() << QString::fromStdString(sug);
    }
}

// Переопределяем функцию подсветки текста
void SpellingHighlighter::highlightBlock(const QString &text)
{
    QStringList list = text.split(QRegularExpression("\\s+"),
            Qt::KeepEmptyParts); //Регулярное выражения по поиску слов
    QTextCharFormat
            spellingFormat; //Определяем как именно мы будем подсвечивать слова
    spellingFormat.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
    spellingFormat.setUnderlineColor(Qt::red);
    qsizetype count_word = list.size();
    qsizetype pointer = 0;
    qDebug() << "Start";
    for (qsizetype i = 0; i < count_word; i++) {
        bool correct = false;
        QString sect = text.section(QRegularExpression("\\s+"), i, i,
                QString::SectionIncludeLeadingSep);
        qsizetype len = sect.length();
        qsizetype beginLetter = BeginLetter(sect);
        qsizetype endLetter = EndLetter(sect);
        auto sectView = QStringView(sect);
        if (beginLetter != len && endLetter != len) {
            sectView =
                    sectView.sliced(beginLetter, endLetter - beginLetter + 1);
        }
        //sectView = sectView.trimmed();
        //sect.remove(QRegularExpression("[,!?&*|]")); // Удаляем лишние символы
        qDebug() << sectView;

        //Проверяем корректно ли слово
        correct = spellDictionary->spell(sectView);
        if (!correct) {
            setFormat(static_cast<int>(pointer + beginLetter),
                    static_cast<int>(endLetter - beginLetter + 1),
                    spellingFormat);
        }
        pointer += len;
    }
}

qsizetype SpellingHighlighter::BeginLetter(const QString &word)
{
    auto len = word.count();
    if (len == 0) {
        return 0;
    }
    for (qsizetype index = 0; index < len; ++index) {
        if (word.at(index).isLetterOrNumber()) {
            return index;
        }
    }
    return len;
}

qsizetype SpellingHighlighter::EndLetter(const QString &word)
{
    auto len = word.count();
    if (len == 0) {
        return 0;
    }
    for (qsizetype index = len - 1; index >= 0; --index) {
        if (word.at(index).isLetterOrNumber()) {
            return index;
        }
    }
    return len;
};

SpellTextEdit::SpellTextEdit(QWidget *parent /*= nullptr*/) : QTextEdit(parent)
{
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    spellDictionary = new SpellDictionary(file_name_aff, file_name_dic);
    m_highLighter = new SpellingHighlighter(spellDictionary, this->document());

    spellDictionary->test("Привет");
    spellDictionary->test("Превет");

    connect(this, SIGNAL(customContextMenuRequested(QPoint)), this,
            SLOT(openCustomMenu(QPoint)));
}

SpellTextEdit::~SpellTextEdit()
{
    delete spellDictionary;
}

//Создание контекстного меню с предложенными вариантами замены
void SpellTextEdit::openCustomMenu(QPoint pos)
{
    QMenu *popupmenu = this->createStandardContextMenu();
    QTextCursor cursor = this->textCursor();
    cursor.select(QTextCursor::WordUnderCursor);
    this->setTextCursor(cursor);
    if (this->textCursor().hasSelection()) {
        QString text = this->textCursor().selectedText();
        bool correct = false;
        QStringList suggest = suggestCorrections(text, correct, true);
        auto *firstAction = popupmenu->actions().first();
        if (!correct) {
            QList<QAction *> addedActions;
            for (auto word : suggest) {
                auto *act = new QAction(word, popupmenu);
                act->setData(word);
                addedActions.append(act);
            }
            popupmenu->insertActions(firstAction, addedActions);
            // clang-format off
            connect(popupmenu, SIGNAL(triggered(QAction*)),
                    this, SLOT(correctWord(QAction*)));
            // clang-format on
        }
    }
    popupmenu->exec(this->mapToGlobal(pos));
    delete popupmenu;
}

//Замена слова на выбранное в меню
void SpellTextEdit::correctWord(QAction *act)
{
    if (act->data().isNull())
        return;
    QString word = act->data().toString();
    QTextCursor cursor = this->textCursor();
    cursor.beginEditBlock();

    cursor.removeSelectedText();
    cursor.insertText(word);
    cursor.endEditBlock();
}

QStringList SpellTextEdit::suggestCorrections(
        const QString &word, bool &correct, bool getSuggests /*= false*/)
{

    correct = spellDictionary->spell(word);
    if (getSuggests == false)
        return QStringList();

    std::vector<std::string> out;
    QStringList suggestions;
    spellDictionary->suggest(word, suggestions);
    return suggestions;
}
