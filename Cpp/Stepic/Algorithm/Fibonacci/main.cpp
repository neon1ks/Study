#include <cassert>
#include <iostream>

class Fibonacci final
{
public:
    static int get(int n)
    {
        assert(n >= 0);
        int a = 0;
        int b = 1;
        for (int i = 1; i < n; ++i) {
            int t = a + b;
            a = b;
            b = t;
        }
        // put your code here
        return b;
    }
};

int main(void)
{
    int n;
    std::cin >> n;
    std::cout << Fibonacci::get(n) << std::endl;
    return 0;
}
