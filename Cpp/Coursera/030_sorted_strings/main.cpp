#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SortedStrings
{
public:
    void AddString(const string &s) { strings.push_back(s); }
    vector<string> GetSortedStrings()
    {
        // получить набор из всех добавленных строк в отсортированном порядке
        sort(strings.begin(), strings.end());
        return strings;
    }

private:
    // приватные поля
    vector<string> strings;
};

void MyPrintSortedStrings(SortedStrings &strings)
{
    for (const string &s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main()
{
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    MyPrintSortedStrings(strings);

    strings.AddString("second");
    MyPrintSortedStrings(strings);

    return 0;
}

/*
class SortedStrings {
public:
  void AddString(const string& s) {
    data.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(data), end(data));
    return data;
  }
private:
  vector<string> data;
};
*/
