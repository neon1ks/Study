#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int get_length_of_longest_divisible_subsequence(const std::vector<int> &numbers) {
    // TODO optimize this function
    int result = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        int first_number = numbers[i];

        std::vector<int> left_numbers;
        std::remove_copy_if(numbers.begin() + i + 1, numbers.end(), std::back_inserter(left_numbers), [first_number] (int number) { return number % first_number != 0; });
        auto current_result = 1 + get_length_of_longest_divisible_subsequence(left_numbers);
        if (current_result > result) {
            result = current_result;
        }
    }
    return result;
}

int main() {
    size_t number_count = 0;
    std::cin >> number_count;
    std::vector<int> numbers(number_count);
    for (auto &number:numbers) {
        std::cin >> number;
    }

    std::cout << get_length_of_longest_divisible_subsequence(numbers) << std::endl;
}
