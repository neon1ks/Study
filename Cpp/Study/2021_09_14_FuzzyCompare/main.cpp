#include <cmath>
#include <iomanip>
#include <iostream>

constexpr const double PI = 3.141592653589793;

using namespace std;

// Проверка на равенство вещественных чисел, взято из Qt
// https://github.com/qt/qtbase/blob/dev/src/corelib/global/qglobal.h

[[nodiscard]] constexpr bool qFuzzyCompare(double p1, double p2)
{
    return (abs(p1 - p2) * 1000000000000. <= min(abs(p1), abs(p2)));
}

[[nodiscard]] constexpr bool qFuzzyCompare(float p1, float p2)
{
    return (abs(p1 - p2) * 100000.F <= min(abs(p1), abs(p2)));
}

[[nodiscard]] constexpr bool qFuzzyIsNull(double d)
{
    return abs(d) <= 0.000000000001;
}

[[nodiscard]] constexpr bool qFuzzyIsNull(float f)
{
    return abs(f) <= 0.00001F;
}

int main()
{
    double x = 0.7;
    double a = 1.65;
    double Q{};
    const double x_end = 2.0;

    while (x < x_end || qFuzzyCompare(x, x_end)) {

        if (x < 1.4) {
            Q = PI * pow(x, 2) - 7 / pow(x, 2);
        } else if (qFuzzyCompare(x, 1.4)) {
            Q = a * pow(x, 2) + 7 * sqrt(x);
        } else {
            Q = log(x + 7 * sqrt(abs(x + a)));
        }
        cout << "x = " << setw(3) << x << ", Q = " << setw(9) << Q << endl;
        x += 0.1;
    }

    return 0;
}
