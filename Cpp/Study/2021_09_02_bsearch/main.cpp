#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

const int COUNT = 30;

void print_array(const std::vector<int> &values)
{
    for (const auto &v : values) {
        std::cout << v << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    // Seed with a real random value, if available
    std::random_device r;

    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(10, 20);

    std::vector<int> values(COUNT);
    for (auto &v : values) {
        v = uniform_dist(e1);
    }

    print_array(values);

    std::sort(values.begin(), values.end());

    print_array(values);

    int mean = uniform_dist(e1);
    std::cout << "mean = " << mean << std::endl;

    auto it = std::lower_bound(values.begin(), values.end(), mean);
    if (it == values.end()) {
        std::cout << "Не найдено" << std::endl;
    } else {
        int index = static_cast<int>(it - values.begin());
        std::cout << "index = " << index << std::endl;
    }

    return 0;
}
