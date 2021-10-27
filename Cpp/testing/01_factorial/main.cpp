#include <iostream>
#include <vector>
#include <limits>

using namespace std;
unsigned long long F_test()
{
    unsigned long long result = 1;
    unsigned long long index = 2;
    unsigned long long check =
            numeric_limits<unsigned long long>::max() / index + 1;
    while (check > result) {
        result *= index;
        ++index;
        check = numeric_limits<unsigned long long>::max() / index + 1;
    }
    return index;
}

// Итеративная версия
unsigned long long F_iterative(unsigned long long n)
{
    if (n > 21) {
        return 0;  // Иначе будет переполнение unsigned long long
    }
    unsigned long long result = 1;
    for (unsigned long long i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// рекурсивная версия
// https://releases.llvm.org/13.0.0/tools/clang/tools/extra/docs/clang-tidy/checks/misc-no-recursion.html
// function 'F_recursive' is within a recursive call chain [misc-no-recursion]
unsigned long long F_recursive(unsigned long long n)
{
    if (n > 21) {  // Иначе будет переполнение unsigned long long
        return 0;  // Для больший значений нужно использовать специальные классы
    }
    if (n < 2) {
        return n;
    }
    return n * F_recursive(n - 1);
}

class Factorial
{
private:
    static const int N;  // = 21;
    static vector<unsigned long long> cache;

public:
    static unsigned long long F(unsigned long long n)
    {

        if (n > 21) {
            return 0;  // Иначе будет переполнение unsigned long long
        }
        if (n < 2) {
            return n;
        }
        if (cache[n] == 0) {
            cache[n] = n * Factorial::F(n - 1);
        }
        if (n == 21) {
            for (const auto &c : cache) {
                cout << c << ' ';
            }
            cout << endl;
        }
        return cache[n];
    }
};

const int Factorial::N = 21;
vector<unsigned long long> Factorial::cache =
        vector<unsigned long long>(Factorial::N + 1, 0);

int main()
{
    cout << "F_test() = " << F_test() << endl;
    cout << "F_iterative(21) = " << F_iterative(21) << endl;
    cout << "F_recursive(21) = " << F_recursive(21) << endl;
    cout << "Factorial::F(21) = " << Factorial::F(21) << endl;
    cout << endl;
    return 0;
}

// Обычно итеративные функции работают быстрее рекурсивных.
// В данном случае большой разницы я не вижу. Здесь нет лищних повторых
// вызовов в рекурсивной версии. Зато активно используется стек процессора.
// Переполнения стека может и не будет, но это всё равно не очень хорошо.

// Итеративная версия версия будет работать быстрее, засчет того
// что она совершает меньше действий, не нужно делать дополнительные
// вызовы функций.

// Рекурсивную версию можно дополнить кешем, и тогда она при многократном
// использовании будет работать быстрее,
// но будет потреблять дополнительную память
