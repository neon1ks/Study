#include <iostream>
#include <limits>

int main()
{

    unsigned char uc = 255;
    std::cout << "uc = " << +uc << std::endl;
    std::cout << "sizeof(uc) = " << sizeof(uc) << std::endl;
    std::cout << "unsigned char max = "
              << +std::numeric_limits<unsigned char>::max() << std::endl;
    std::cout << std::endl;

    signed char sc = -15;
    std::cout << "sc = " << +sc << std::endl;
    std::cout << "sizeof(sc) = " << sizeof(sc) << std::endl;
    std::cout << "signed char max = "
              << +std::numeric_limits<signed char>::max() << std::endl;
    std::cout << std::endl;

    char c = 97;
    std::cout << "c = " << +c << std::endl;
    std::cout << "sizeof(c) = " << sizeof(c) << std::endl;
    std::cout << "char max = " << +std::numeric_limits<char>::max()
              << std::endl;
    std::cout << std::endl;

    long long ll = 97;
    std::cout << "ll = " << +ll << std::endl;
    std::cout << "sizeof(ll) = " << sizeof(ll) << std::endl;
    std::cout << "long long max = " << +std::numeric_limits<long long>::max()
              << std::endl;
    std::cout << std::endl;

    long double ld = 192.159L;
    std::cout << "ld = " << ld << std::endl;
    std::cout << "sizeof(ld) = " << sizeof(ld) << std::endl;
    std::cout << "long double max = "
              << +std::numeric_limits<long double>::max() << std::endl;
    std::cout << std::endl;

    // clang-format off
    int number = 2'000'000'000;
                 // clang-format on

                 std::cout
                 << number << std::endl;

    return 0;
}
