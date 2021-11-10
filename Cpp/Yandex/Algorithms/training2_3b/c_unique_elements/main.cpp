#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    set<int> numbers = {};
    vector<int> result = {};
    int number = {};

    string line;
    getline(cin, line);
    istringstream line_stream(line);

    while (line_stream >> number) {
        auto r = numbers.insert(number);
        if (r.second) {
            result.push_back(number);
        } else {
            auto it = find(result.begin(), result.end(), number);
            if (it != result.end()) {
                result.erase(it);
            }
        }
    }

    bool first = true;
    for (auto &e : result) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << e;
    }
    cout << endl;
    return 0;
}
