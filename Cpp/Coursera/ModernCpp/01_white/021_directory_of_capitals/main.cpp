#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    size_t count = 0;
    cin >> count;
    map<string, string> capitals;
    for (size_t i = 0; i < count; ++i) {
        static string cmd;
        cin >> cmd;
        if (cmd == "CHANGE_CAPITAL") {
            string country;
            string new_capital;
            cin >> country >> new_capital;
            if (capitals.find(country) == capitals.end()) {
                capitals[country] = new_capital;
                cout << "Introduce new country " << country << " with capital "
                     << new_capital << endl;
            } else {
                if (capitals[country] == new_capital) {
                    cout << "Country " << country
                         << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country
                         << " has changed its capital from "
                         << capitals[country] << " to " << new_capital << endl;
                    capitals[country] = new_capital;
                }
            }
        } else if (cmd == "RENAME") {
            string old_country_name;
            string new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name
                    || capitals.find(old_country_name) == capitals.end()
                    || capitals.find(new_country_name) != capitals.end()) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
                cout << "Country " << old_country_name << " with capital "
                     << capitals[new_country_name] << " has been renamed to "
                     << new_country_name << endl;
            }
        } else if (cmd == "ABOUT") {
            string country;
            cin >> country;
            if (capitals.find(country) == capitals.end()) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital "
                     << capitals[country] << endl;
            }
        } else if (cmd == "DUMP") {
            if (capitals.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                bool first = true;
                for (const auto &capital : capitals) {
                    if (first) {
                        first = false;
                    } else {
                        cout << ' ';
                    }
                    cout << capital.first << '/' << capital.second;
                }
                cout << endl;
            }
        }
    }
    return 0;
}

/*
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, string> country_to_capital;

    for (int i = 0; i < q; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "CHANGE_CAPITAL") {

            string country, new_capital;
            cin >> country >> new_capital;
            if (country_to_capital.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else {
                const string& old_capital = country_to_capital[country];
                if (old_capital == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                }
            }
            country_to_capital[country] = new_capital;

        } else if (operation_code == "RENAME") {

            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
                    " has been renamed to " << new_country_name << endl;
                country_to_capital[new_country_name] = country_to_capital[old_country_name];
                country_to_capital.erase(old_country_name);
            }

        } else if (operation_code == "ABOUT") {

            string country;
            cin >> country;
            if (country_to_capital.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
            }

        } else if (operation_code == "DUMP") {

            if (country_to_capital.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& country_item : country_to_capital) {
                    cout << country_item.first << "/" << country_item.second << " ";
                }
                cout << endl;
            }

        }

    }

    return 0;
}
*/
