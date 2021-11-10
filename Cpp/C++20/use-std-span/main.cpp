#include <algorithm>
#include <iostream>
#include <span>

int main()
{
    int data[] = { 5, 3, 2, 1, 4 };
    std::span<int> s{ data, 5 };

    std::sort(s.begin(), s.end());

    for (auto const i : s) {
        std::cout << i << "\n";
    }

    return 0;
}
