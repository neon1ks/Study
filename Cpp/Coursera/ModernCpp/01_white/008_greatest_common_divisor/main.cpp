#include <cassert>
#include <cstdint>
#include <utility>
#include <iostream>

using namespace std;

template<class Int>
Int gcd(Int a, Int b)
{
    assert(a > 0 && b > 0);
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

int main()
{
    int a = 0;
    int b = 0;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

/*
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // пока оба числа положительны, будем их уменьшать, не меняя их НОД
    while (a > 0 && b > 0) {

        // возьмём большее из чисел и заменим его остатком от деления на второе
        // действительно, если a и b делятся на x, то a - b и b делятся на x
        // тогда и a % b и b делятся на x, так что можно a заменить на a % b
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }

    }

    // если одно из чисел оказалось равно нулю, значит, на последней итерации
    // большее число разделилось на меньшее
    cout << a + b;

    return 0;
}
*/
