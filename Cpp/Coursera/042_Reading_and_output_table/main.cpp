#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    const string file_name = "input.txt";
    ifstream input(file_name);
    size_t N = 0;
    size_t M = 0;
    input >> N >> M;
    for (size_t i = 0; i < N; ++i) {
        int a = 0;
        for (size_t j = 0; j < M - 1; ++j) {
            input >> a;
            input.ignore(1);
            cout << setw(10) << a;
            cout << setw(1) << ' ';
        }
        input >> a;
        cout << setw(10) << a;
        if (i < N - 1) {
            cout << setw(1) << endl;
        }
    }
    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  ifstream input("input.txt");

  int n, m;
  input >> n >> m;

  // перебираем строки
  for (int i = 0; i < n; ++i) {
    // перебираем столбцы
    for (int j = 0; j < m; ++j) {
      // считываем очередное число
      int x;
      input >> x;
      // пропускаем следующий символ
      input.ignore(1);
      // выводим число в поле ширины 10
      cout << setw(10) << x;
      // выводим пробел, если только этот столбец не последний
      if (j != m - 1) {
        cout << " ";
      }
    }
    // выводим перевод строки, если только эта строка не последняя
    if (i != n - 1) {
      cout << endl;
    }
  }

  return 0;
}
*/
