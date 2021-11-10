#include <iostream>
#include <map>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string> &m)
{
    set<string> result;
    for (const auto &e : m) {
        result.insert(e.second);
    }
    return result;
}

/* cut begin */
int main()
{
    set<string> values = BuildMapValuesSet({ { 1, "odd" }, { 2, "even" },
            { 3, "odd" }, { 4, "even" }, { 5, "odd" } });

    for (const string &value : values) {
        cout << value << endl;
    }
    return 0;
}
/* cut end */

/*
set<string> BuildMapValuesSet(const map<int, string>& m) {
  set<string> values;
  for (const auto& item : m) {
    values.insert(item.second);
  }
  return values;
}
*/
