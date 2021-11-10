#include <iostream>

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;

    std::cin >> a >> b >> c;

    if (c < 0 || a == 0 && b != c * c) {
        std::cout << "NO SOLUTION" << std::endl;
    } else if (a == 0 && b == c * c) {
        std::cout << "MANY SOLUTIONS" << std::endl;
    } else {
        if ((c * c - b) % a == 0) {
            std::cout << (c * c - b) / a << std::endl;
        } else {
            std::cout << "NO SOLUTION" << std::endl;
        }
    }

    return 0;
}
