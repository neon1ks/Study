#include <iostream>
#include <cmath>

const double PI = 3.141592653589793;

// Проверка на равенство вещественных чисел, взято из Qt
bool FuzzyCompare(double p1, double p2)
{
    return (std::abs(p1 - p2) * 1000000000000.
            <= std::min(std::abs(p1), std::abs(p2)));
}
static inline bool FuzzyCompare(float p1, float p2)
{
    return (std::abs(p1 - p2) * 100000.F
            <= std::min(std::abs(p1), std::abs(p2)));
}

int main()
{
    double x = 0.7;
    double a = 1.65;
    double Q = 0;
    const double x_end = 2.0;

    while (x < x_end || FuzzyCompare(x, x_end)) {

        if (x < 1.4) {
            Q = PI * std::pow(x, 2) - 7 / std::pow(x, 2);
        } else if (FuzzyCompare(x, 1.4)) {
            Q = a * std::pow(x, 2) + 7 * std::sqrt(x);
        } else {
            Q = std::log(x + 7 * std::sqrt(std::abs(x + a)));
        }
        std::cout << "x = " << x << ", Q = " << Q << std::endl;
        x += 0.1;
    }
    return 0;
}
