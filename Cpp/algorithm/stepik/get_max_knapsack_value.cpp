#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

struct Item final
{
    int weight;
    int value;
};

double get_max_knapsack_value(int capacity, std::vector<Item> items)
{
    double value = 0.0;

    sort(items.begin(), items.end(), [](const Item &a, const Item &b) -> bool {
        return static_cast<double>(a.value) / static_cast<double>(a.weight)
               > static_cast<double>(b.value) / static_cast<double>(b.weight);
    });

    for (auto &item : items) {
        if (capacity > item.weight) {
            capacity -= item.weight;
            value += item.value;
        } else {
            value += item.value * (static_cast<double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main(void)
{
    int number_of_items;
    int knapsack_capacity;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector<Item> items(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
        std::cin >> items[i].value >> items[i].weight;
    }

    double max_knapsack_value =
            get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << std::fixed << std::setprecision(3) << max_knapsack_value
              << std::endl;
    return 0;
}
