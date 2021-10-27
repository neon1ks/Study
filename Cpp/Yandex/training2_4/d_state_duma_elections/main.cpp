#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

struct greater_comp
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

int main()
{
    vector<string> party_list;
    map<string, size_t> elections;
    vector<pair<double, string>> remainder;
    map<string, size_t> chairs;

    string line;
    size_t all_count{};

    while (getline(cin, line)) {
        auto index = line.find_last_of(" ");
        string name = line.substr(0, index);
        size_t count = stoul(line.substr(index + 1));

        party_list.emplace_back(name);
        elections[name] = count;
        all_count += count;
    }

    double first_value = static_cast<double>(all_count) / 450.0F;
    size_t all_chairs = 0;
    for (const auto &name : party_list) {
        auto a = static_cast<double>(elections[name]) / first_value;
        auto b = floor(a);
        chairs[name] = static_cast<size_t>(b);
        all_chairs += chairs[name];
        remainder.emplace_back(a - b, name);
    }

    sort(remainder.begin(), remainder.end(), greater_comp());
    //reverse(remainder.begin(), remainder.end());

    for (const auto &[r, name] : remainder) {
        if (all_chairs >= 450) {
            break;
        }
        ++chairs[name];
        ++all_chairs;
    }

    for (const auto &name : party_list) {
        cout << name << ' ' << chairs[name] << endl;
    }

    return 0;
}
