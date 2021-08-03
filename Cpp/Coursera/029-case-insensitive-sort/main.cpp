#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::string str_tolower(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); });
    return s;
}

int main()
{

    size_t count = 0;
    cin >> count;
    vector<string> strings(count);

    for (auto &s : strings) {
        cin >> s;
    }

    sort(strings.begin(), strings.end(),
            [](const string &l, const string &r) -> bool {
                return str_tolower(l) < str_tolower(r);
            });

    for (const auto &n : strings) {
        cout << n << ' ';
    }
    cout << endl;

    return 0;
}

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  // считываем вектор строк
  int n;
  cin >> n;
  vector<string> v(n);
  for (string& s : v) {
    cin >> s;
  }

  // сортируем
  sort(begin(v), end(v),
       // компаратор для сортировки — лямбда-функция, сравнивающая строки без учёта регистра
       [](const string& l, const string& r) {
         // сравниваем лексикографически...
         return lexicographical_compare(
             // ... все символы строки l ...
             begin(l), end(l),
             // ... со всеми символами строки r ...
             begin(r), end(r),
             // ..., используя в качестве компаратора сравнение отдельных символов без учёта регистра
             [](char cl, char cr) { return tolower(cl) < tolower(cr); }
         );
       }
  );

  // выводим отсортированный вектор
  for (const string& s : v) {
    cout << s << ' ';
  }

  return 0;
}
*/
