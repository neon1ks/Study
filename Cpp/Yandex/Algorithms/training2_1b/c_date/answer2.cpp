#include <iostream>

int algorithm(int a, int b, int c)
{
    if ((a < 13 && b >= 13 && c >= 1970) || (a >= 13 && b < 13 && c >= 1970)
            || (a == b && a < 13 && c >= 1970)) {
        return 1;
    }

    return 0;
}

int main()
{
    int a = {};
    int b = {};
    int c = {};
    std::cin >> a >> b >> c;
    int result = algorithm(a, b, c);
    std::cout << result << std::endl;
}
