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
