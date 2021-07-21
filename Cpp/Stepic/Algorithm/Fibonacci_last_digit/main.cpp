#include <cassert>
#include <iostream>

class Fibonacci final
{
public:
    static int get_last_digit(int n)
    {
        assert(n >= 1);
        int a = 0;
        int b = 1;
        for (int i = 1; i < n; ++i) {
            int t = a + b;
            a = b;
            b = t % 10;
        }
        return b;
    }
};

int main(void)
{
    int n;
    std::cin >> n;
    while (!std::cin.eof()) {
        std::cout << Fibonacci::get_last_digit(n) << std::endl;
        std::cin >> n;
    }
    return 0;
}
