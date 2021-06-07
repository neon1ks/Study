#ifndef SPELLTEXTEDIT_H
#define SPELLTEXTEDIT_H

#include <QSyntaxHighlighter>
#include <QTextEdit>
#include <string>

#include <nuspell/dictionary.hxx>
#include <nuspell/finder.hxx>

class SpellDictionary
{
public:
    SpellDictionary(const std::string &aff, const std::string &dic);
    SpellDictionary() = delete;
    ~SpellDictionary() = default;

    bool spell(QStringView word);
    void suggest(const QString &word, QStringList &out);
    void test(const QString &word);

    static bool isRussian(QStringView word);

private:
    nuspell::v4::Dictionary dict;
};

// Класс для подсвечивания текста
class SpellingHighlighter
    : public QSyntaxHighlighter // Класс для подсвечивания текста
{
    Q_OBJECT

public:
    SpellingHighlighter(SpellDictionary *refSpellDictionary,
            QTextDocument *parent = nullptr)
        : QSyntaxHighlighter(parent), spellDictionary(refSpellDictionary)
    {
    }

protected:
    void highlightBlock(const QString &text) override;

private:
    SpellDictionary *spellDictionary;
    static qsizetype BeginLetter(const QString &word);
    static qsizetype EndLetter(const QString &word);
};

// Класс для ввода и отображения текста
class SpellTextEdit : public QTextEdit
{
    Q_OBJECT
public:
    explicit SpellTextEdit(QWidget *parent = nullptr);
    virtual ~SpellTextEdit();

public slots:
    void openCustomMenu(QPoint);
    void correctWord(QAction *act);

protected:
    SpellingHighlighter *m_highLighter;
    SpellDictionary *spellDictionary;

private:
    QStringList suggestCorrections(
            const QString &word, bool &correct, bool getSuggests = false);
};

#endif // SPELLTEXTEDIT_H
