#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    unsigned count = {};
    cin >> count;
    cin.get();

    vector<unsigned> messages(count, 0);
    map<unsigned, unsigned> themes;
    vector<string> titles;
    unsigned index = 0;

    for (unsigned i = 0; i < count; ++i) {
        unsigned number = {};
        cin >> number;
        cin.get();
        if (number == 0) {
            string title;
            getline(cin, title);
            messages[i] = index;
            ++themes[index];
            titles.emplace_back(title);
            string text;
            getline(cin, text);
            ++index;
        } else {
            messages[i] = messages[number - 1];
            ++themes[messages[i]];
            string text;
            getline(cin, text);
        }
    }

    unsigned maximum = 0;
    index = 0;
    for (auto &[id, value] : themes) {
        if (value > maximum) {
            maximum = value;
            index = id;
        }
    }

    cout << titles[index] << endl;
    return 0;
}
