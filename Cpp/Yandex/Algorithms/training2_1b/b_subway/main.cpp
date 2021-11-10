#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int algorithm(int n, int a, int b)
{
    int one = (a > b ? a - b - 1 : b - a - 1);
    int two = (a > b ? b + n - a - 1 : a + n - b - 1);
    return (one < two ? one : two);
}

int wrap_algorithm(istream &in, ostream &out)
{
    try {
        int n = {};
        int a = {};
        int b = {};
        in >> n >> a >> b;
        int result = algorithm(n, a, b);
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
