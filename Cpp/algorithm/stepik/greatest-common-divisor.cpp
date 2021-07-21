#include <cassert>
#include <cstdint>
#include <iostream>

template <class Int>
Int gcd(Int a, Int b) {
  assert(a > 0 && b > 0);
    Int first{};
    Int second{};

    if (a > b) {
        first = a;
        second = b;
    } else {
        first = b;
        second = a;
    }

    while (second > 0) {
        Int temp = first % second;
        first = second;
        second = temp;
    }

    return first;
}

int main(void) {
  std::int32_t a, b;
  std::cin >> a >> b;
  std::cout << gcd(a, b) << std::endl;
  return 0;
}

