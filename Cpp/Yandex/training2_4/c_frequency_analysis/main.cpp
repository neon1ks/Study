#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    string word;
    map<string, size_t> analysis;

    while (cin >> word) {
        ++analysis[word];
    }

    vector<pair<size_t, string>> result;
    for (const auto &[key, value] : analysis) {
        result.emplace_back(value, key);
    }

    sort(result.begin(), result.end(),
            [](const pair<size_t, string> &a,
                    const pair<size_t, string> &b) -> bool {
                return a.first == b.first ? a.second < b.second
                                          : a.first > b.first;
            });

    for (const auto &r : result) {
        cout << r.second << endl;
    }

    return 0;
}
