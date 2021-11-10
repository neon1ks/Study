#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLenght)
{
    vector<string> result;
    for (auto word : words) {
        bool check = true;
        for (size_t i = 0; i < word.size() / 2; ++i) {
            if (word[i] != word[word.size() - i - 1]) {
                check = false;
                break;
            }
        }
        if (check && word.size() >= minLenght) {
            result.push_back(word);
        }
    }
    return result;
}

int main()
{
    int n = 0;
    cin >> n;
    cin.get();
    vector<string> words;
    for (int i = 0; i < n; ++i) {
        string temp;
        getline(cin, temp);
        words.push_back(temp);
    }
    int minLenght = 0;
    cin >> minLenght;
    cin.get();
    auto result = PalindromFilter(words, minLenght);
    for (auto &word : result) {
        cout << word << ' ';
    }
    cout << endl;
    return 0;
}

/*
// определяет, является ли строка s палиндромом
bool IsPalindrom(string s) {

  // переберём все символы s[i] из первой половины строки
  for (size_t i = 0; i < s.size() / 2; ++i) {
    // s[s.size() - i - 1] — символ, симметричный символу s[i]
    if (s[i] != s[s.size() - i - 1]) {
      return false;  // если они не совпадают, строка точно не палиндром
    }
  }

  // если все пары символов совпадают, строка — палиндром
  return true;
}

vector<string> PalindromFilter(vector<string> words, int min_length) {
  vector<string> result;
  // перебираем все элементы вектора words
  for (auto s : words) {
    // если требуеые условия выполняются, добавляем s к ответу
    if (s.size() >= min_length && IsPalindrom(s)) {
      result.push_back(s);
    }
  }
  return result;
}
*/
