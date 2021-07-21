#include <cassert>
#include <iostream>
#include <vector>

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
        return b;
    }
    static int get_remainder(int64_t n, int m)
    {
        assert(n >= 1);
        assert(m >= 2);

        std::vector<int> list;
        list.push_back(0);
        list.push_back(1);
        list.push_back(1);

        int64_t a = 1;
        int64_t b = 1;
        int indexEnd = 0;
        for (int i = 2; i < n; ++i) {
            int64_t t = a + b;
            a = b;
            b = t % m;
            list.push_back(b);
            std::cout << i << " " << b << " (" << b % m << ")\n";
            if (list[i - 1] == 0 && list[i] == 1 && list[i + 1] == 1) {
                indexEnd = i - 1;
                break;
            }
        }

        std::cout << "indexEnd = "
                  << " " << indexEnd << "\n";

        return (indexEnd > 0 ? list[n % indexEnd] : b % m);
    }
};

int main()
{
    int64_t n;
    int m;
    std::cin >> n >> m;
    std::cout << Fibonacci::get_remainder(n, m) << std::endl;
    return 0;
}
