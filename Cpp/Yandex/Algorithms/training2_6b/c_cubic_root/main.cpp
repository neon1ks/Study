#include <iostream>
#include <cmath>
using namespace std;

[[nodiscard]] constexpr bool qFuzzyIsNull(double f)
{
    return std::abs(f) <= 0.0000001F;
}

int main()
{
    double b = {};
    double a = {};
    double c = {};
    double d = {};
    cin >> a >> b >> c >> d;
    double l = -10000000.0F;
    double r = 10000000.0F;
    double corr = a > 0 ? 1.0 : -1.0;
    while (!qFuzzyIsNull(r - l)) {
        double m = l + (r - l) / 2.0;
        auto result = a * pow(m, 3) + b * pow(m, 2) + c * m + d;
        result *= corr;
        if (result < 0) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << endl;

    return 0;
}
