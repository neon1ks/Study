#include <iostream>
#include <vector>
#include <algorithm>

const int N = 3;

int main()
{
    std::vector<int> lines(N);
    for (auto &line : lines) {
        std::cin >> line;
    }

    std::sort(lines.begin(), lines.end());

    //    for (auto &line : lines) {
    //        std::cout << line << " ";
    //    }

    if (lines[0] <= 0 || lines[1] <= 0 || lines[2] <= 0
            || lines[2] >= lines[1] + lines[0]) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}
