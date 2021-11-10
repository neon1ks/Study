#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

class Person
{
public:
    Person(const string &first_name, const string &last_name, int year)
    {
        history[year] = { first_name, last_name };
        born = year;
    }

    void ChangeFirstName(int year, const string &first_name)
    {
        if (born <= year) {
            history[year].FirstName = first_name;
        }
    }
    void ChangeLastName(int year, const string &last_name)
    {
        if (born <= year) {
            history[year].LastName = last_name;
        }
    }
    string GetFullName(int year) const
    {
        string first_name;
        string last_name;

        for (const auto &y : history) {
            if (year < y.first) {
                break;
            }
            if (!y.second.FirstName.empty()) {
                first_name = y.second.FirstName;
            }
            if (!y.second.LastName.empty()) {
                last_name = y.second.LastName;
            }
            if (year == y.first) {
                break;
            }
        }

        if (first_name.empty() && last_name.empty()) {
            return "No person";
        }
        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        return first_name + ' ' + last_name;
    }

    string GetFullNameWithHistory(int year) const
    {
        vector<string> first_name;
        vector<string> last_name;

        for (const auto &y : history) {
            if (year < y.first) {
                break;
            }
            if (!y.second.FirstName.empty()) {
                if (first_name.empty()
                        || first_name.back() != y.second.FirstName) {
                    first_name.push_back(y.second.FirstName);
                }
            }
            if (!y.second.LastName.empty()) {
                if (last_name.empty()
                        || last_name.back() != y.second.LastName) {
                    last_name.push_back(y.second.LastName);
                }
            }
            if (year == y.first) {
                break;
            }
        }

        if (first_name.empty() && last_name.empty()) {
            return "No person";
        }
        if (first_name.empty()) {
            return getNames(last_name) + " with unknown first name";
        }
        if (last_name.empty()) {
            return getNames(first_name) + " with unknown last name";
        }
        return getNames(first_name) + ' ' + getNames(last_name);
    }

private:
    struct FirstAndLastName
    {
        string FirstName;
        string LastName;
    };
    map<int, FirstAndLastName> history;
    int born;

    static string getNames(const vector<string> &v)
    {
        string result = v.back();
        if (v.size() > 1) {
            result += " (";
            size_t i = v.size() - 1;
            do {
                --i;
                result += v[i];
                if (i != 0) {
                    result += ", ";
                }
            } while (i > 0);
            result += ')';
        }
        return result;
    };
    // приватные поля
};

int main()
{
    Person person("Polina", "Sergeeva", 1960);
    for (int year : { 1959, 1960 }) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : { 1965, 1967 }) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}

/*
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
                                int year) {
  vector<string> names;
  for (const auto& item : names_by_year) {
    if (item.first <= year && (names.empty() || names.back() != item.second)) {
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names) {
  reverse(begin(names), end(names));
  string joined_name = names[0];
  for (int i = 1; i < names.size(); ++i) {
    if (i == 1) {
      joined_name += " (";
    } else {
      joined_name += ", ";
    }
    joined_name += names[i];
  }
  if (names.size() > 1) {
    joined_name += ")";
  }
  return joined_name;
}

class Person {
public:
  // конструктор
  Person(const string& first_name, const string& last_name,
         int new_birth_year) {
    birth_year = new_birth_year;
    first_names[birth_year] = first_name;
    last_names[birth_year] = last_name;
  }
  void ChangeFirstName(int year, const string& first_name) {
    // игнорируем запись, если год меньше года рождения
    if (year >= birth_year) {
      first_names[year] = first_name;
    }
  }
  void ChangeLastName(int year, const string& last_name) {
    if (year >= birth_year) {
      last_names[year] = last_name;
    }
  }
  string GetFullName(int year) const {
    // обрабатываем случай, когда год меньше года рождения
    if (year < birth_year) {
      return "No person";
    }
    const vector<string> first_names = FindFirstNamesHistory(year);
    const vector<string> last_names = FindLastNamesHistory(year);
    // объединяем имя и фамилию через пробел
    return first_names.back() + " " + last_names.back();
  }
  string GetFullNameWithHistory(int year) const {
    if (year < birth_year) {
      return "No person";
    }
    const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
    const string last_name = BuildJoinedName(FindLastNamesHistory(year));
    return first_name + " " + last_name;
  }
private:
  vector<string> FindFirstNamesHistory(int year) const {
    return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year) const {
    return FindNamesHistory(last_names, year);
  }

  int birth_year;
  map<int, string> first_names;
  map<int, string> last_names;
};
*/
