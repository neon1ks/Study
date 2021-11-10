#include <cmath>
#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

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

struct Answer
{
    int type;
    double x;
    double y;
};

Answer matrix22aedf(double a, double e, double d, double f)
{
    return { 2, e / a, f / d };
}

Answer matrix22becf(double b, double e, double c, double f)
{
    return { 2, f / c, e / b };
}

Answer matrix22x(double a, double c, double e, double f)
{
    double x1 = e / a;
    double x2 = f / c;
    if (qFuzzyCompare(x1, x2)) {
        return { 3, x1, 0 };
    }
    return { 0, 0., 0. };
}

Answer matrix22y(double b, double d, double e, double f)
{
    double y1 = e / b;
    double y2 = f / d;
    if (qFuzzyCompare(y1, y2)) {
        return { 4, 0., y1 };
    }
    return { 0, 0., 0. };
}

Answer matrix32a(double a, double b, double d, double e, double f)
{
    double y = f / d;
    double x = (e - b * y) / a;
    return { 2, x, y };
}

Answer matrix32b(double a, double b, double c, double e, double f)
{
    double x = f / c;
    double y = (e - a * x) / b;
    return { 2, x, y };
}

Answer matrix33(double a, double b, double c, double d, double e, double f)
{
    double d2 = d * a - b * c;
    double f2 = f * a - e * c;
    if (qFuzzyIsNull(d2)) {
        if (qFuzzyIsNull(f2)) {
            return { 1, -a / b, e / b };
        }
        return { 0, 0., 0. };
    }
    return matrix32a(a, b, d2, e, f2);
}

Answer oneEquation(double a, double b, double e)
{
    if (qFuzzyIsNull(a)) {
        return { 4, 0., e / b };
    }
    if (qFuzzyIsNull(b)) {
        return { 3, e / a, 0. };
    }
    return { 1, -a / b, e / b };
}


Answer algorithm(double a, double b, double c, double d, double e, double f)
{

    if ((qFuzzyIsNull(a) && qFuzzyIsNull(b) && !qFuzzyIsNull(e))
            || (qFuzzyIsNull(c) && qFuzzyIsNull(d) && !qFuzzyIsNull(f))) {
        return { 0, 0., 0. };
    }
    if (qFuzzyIsNull(a) && qFuzzyIsNull(b) && qFuzzyIsNull(e) && qFuzzyIsNull(c)
            && qFuzzyIsNull(d) && qFuzzyIsNull(f)) {
        return { 5, 0., 0. };
    }
    if (qFuzzyIsNull(a) && qFuzzyIsNull(b) && qFuzzyIsNull(e)) {
        return oneEquation(c, d, f);
    }
    if (qFuzzyIsNull(c) && qFuzzyIsNull(d) && qFuzzyIsNull(f)) {
        return oneEquation(a, b, e);
    }
    if (qFuzzyIsNull(a) && qFuzzyIsNull(c)) {
        return matrix22y(b, d, e, f);
    }
    if (qFuzzyIsNull(b) && qFuzzyIsNull(d)) {
        return matrix22x(a, c, e, f);
    }
    if (qFuzzyIsNull(a) && qFuzzyIsNull(d)) {
        return matrix22becf(b, e, c, f);
    }
    if (qFuzzyIsNull(c) && qFuzzyIsNull(b)) {
        return matrix22aedf(a, e, d, f);
    }
    if (qFuzzyIsNull(a)) {
        return matrix32a(c, d, b, f, e);
    }
    if (qFuzzyIsNull(c)) {
        return matrix32a(a, b, d, e, f);
    }

    if (qFuzzyIsNull(b)) {
        return matrix32b(c, d, a, f, e);
    }
    if (qFuzzyIsNull(d)) {
        return matrix32b(a, b, c, e, f);
    }

    return matrix33(a, b, c, d, e, f);
}

int main()
{
    double a = { 0 };
    double b = { 0 };
    double c = { 0 };
    double d = { 0 };
    double e = { 0 };
    double f = { 0 };

    cin >> a >> b >> c >> d >> e >> f;

    auto result = algorithm(a, b, c, d, e, f);

    cout << result.type;
    switch (result.type) {
    case 0:
    case 5:
        break;
    case 1:
    case 2:
        cout << ' ' << result.x << ' ' << result.y;
        break;
    case 3:
        cout << ' ' << result.x;
        break;
    case 4:
        cout << ' ' << result.y;
        break;
    default:
        break;
    }
    cout << endl;

    return 0;
}
