#include <iostream>

using namespace std;

bool IsPalindrom(string text)
{

    if (text.empty()) {
        return true;
    }
    size_t i_begin = 0;
    size_t i_end = text.size() - 1;
    while (i_begin < i_end) {
        if (text[i_begin] != text[i_end]) {
            return false;
        }
        ++i_begin;
        --i_end;
    }

    return true;
}

int main()
{
    string text;
    cin >> text;
    cout << IsPalindrom(text) << endl;
    return 0;
}

/*
bool IsPalindrom(string s) {
    // Замечание: более правильным было бы использовать здесь тип size_t вместо int
    // О причинах Вы узнаете на Жёлтом поясе
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}
*/
