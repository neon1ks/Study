#include <iostream>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    size_t N{};
    cin >> N;
    cin.get();
    string command_line;
    map<string, set<string>> newdict;
    for (size_t i = 0; i < N; ++i) {
        getline(cin, command_line);
        stringstream ss(command_line);
        string key;
        string temp;
        ss >> key;
        ss >> temp;
        while (ss >> temp) {
            if (temp[temp.size() - 1] == ',') {
                temp.resize(temp.size() - 1);
            }
            newdict[temp].insert(key);
        }
    }

    cout << newdict.size() << endl;
    for (const auto &d : newdict) {
        cout << d.first << " - ";
        bool first = true;
        for (const auto &v : d.second) {
            if (first) {
                first = false;
            } else {
                cout << ", ";
            }
            cout << v;
        }
        cout << endl;
    }

    return 0;
}
