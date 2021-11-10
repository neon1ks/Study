#include <iostream>
#include <cmath>

using namespace std;

int algorithm(int d, int x, int y)
{
    if (x >= 0 && y >= 0 && x + y <= d) {
        return 0;
    }

    double a = sqrt(pow(x, 2) + pow(y, 2));
    double b = sqrt(pow(x - d, 2) + pow(y, 2));
    double c = sqrt(pow(x, 2) + pow(y - 2, 2));

    if (a <= b && a <= c) {
        return 1;
    }
    if (b <= a && b <= c) {
        return 2;
    }

    return 3;
}

int wrap_algorithm(istream &in, ostream &out)
{
    try {
        int d = {};
        in >> d;

        int x = { 0 };
        int y = { 0 };
        in >> x >> y;

        int result = algorithm(d, x, y);
        out << result << endl;
    } catch (...) {
        return -1;
    }
    return 0;
}

int main()
{
    return wrap_algorithm(cin, cout);
}
