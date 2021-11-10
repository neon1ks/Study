#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isAnagrams(const string &first, const string &second)
{
    map<char, size_t> f;
    for (const auto &c : first) {
        ++f[c];
    }

    map<char, size_t> s;
    for (const auto &c : second) {
        ++s[c];
    }

    return f == s;
}

int main()
{
    size_t n = 0;
    cin >> n;
    string first;
    string second;
    for (size_t i = 0; i < n; ++i) {
        cin >> first;
        cin >> second;
        cout << (isAnagrams(first, second) ? "YES" : "NO") << endl;
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& word) {
    map<char, int> counters;
    for (char c : word) {
        ++counters[c];
    }
    return counters;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string first_word, second_word;
        cin >> first_word >> second_word;
        if (BuildCharCounters(first_word) == BuildCharCounters(second_word)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
*/
