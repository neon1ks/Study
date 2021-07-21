#include <cassert>
#include <cstdint>
#include <utility>
#include <iostream>

template<class Int>
Int gcd(Int a, Int b)
{
    assert(a > 0 && b > 0);
    // optimize this function

    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }

    return a;
}

int main(void)
{
    std::int32_t a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << std::endl;
    return 0;
}
