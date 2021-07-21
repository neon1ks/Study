#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int get_pos(const std::vector<int> &numbers, int number)
{
    // TODO optimize this function
    //auto it = std::find(numbers.begin(), numbers.end(), number);
    //if (it == numbers.end()) {
    //    return -1;
    //}
    //return static_cast<int>(it - numbers.begin()) + 1;

    int l = 0;
    int r = numbers.size() - 1;
    while (l <= r) {
        auto t = l + (r - l) / 2;
        if (numbers[t] == number) {
            return t + 1;
        } else if (numbers[t] > number) {
            r = t - 1;
        } else {
            l = t + 1;
        }
    }
    return -1;
}

int main(void)
{
    size_t number_count;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto &number : numbers) {
        std::cin >> number;
    }
    assert(std::is_sorted(numbers.begin(), numbers.end()));

    size_t query_count;
    std::cin >> query_count;
    while (query_count-- > 0) {
        int number;
        std::cin >> number;
        std::cout << get_pos(numbers, number) << " ";
    }
    std::cout << std::endl;
}
