#include <iostream>
#include <set>
#include <map>

using namespace std;

int main()
{
    map<string, set<string>> synonyms;

    size_t n = 0;
    cin >> n;

    for (size_t i = 0; i < n; ++i) {
        static string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string first;
            string second;
            cin >> first;
            cin >> second;
            synonyms[first].insert(second);
            synonyms[second].insert(first);
        } else if (cmd == "COUNT") {
            string first;
            cin >> first;
            cout << synonyms[first].size() << endl;
        } else if (cmd == "CHECK") {
            string first;
            string second;
            cin >> first;
            cin >> second;
            cout << (synonyms[first].count(second) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
