#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t count = 0;
    cin >> count;
    vector<int> numbers(count);
    for (auto &n : numbers) {
        cin >> n;
    }

    sort(numbers.begin(), numbers.end(),
            [](int a, int b) -> bool { return abs(a) < abs(b); });

    for (const auto &n : numbers) {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

    // считываем вектор
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v) {
        cin >> x;
    }

    // сортируем
    sort(begin(v), end(v),
        // функция, сравнивающая abs(l) и abs(r) — модули чисел l и r
        [](int l, int r) {
            return abs(l) < abs(r);
        }
        );

    // выводим отсорированный вектор
    for (int x : v) {
        cout << x << " ";
    }

    return 0;
}
*/
