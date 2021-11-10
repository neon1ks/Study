#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, size_t> elections;
    string last_name;
    size_t count{};

    while (cin >> last_name >> count) {
        elections[last_name] += count;
    }

    for (const auto &[key, value] : elections) {
        cout << key << ' ' << value << endl;
    }

    return 0;
}
