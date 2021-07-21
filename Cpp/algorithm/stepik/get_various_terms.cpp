#include <iostream>
#include <vector>

using namespace std;

std::vector<int> &get_various_terms(int number, std::vector<int> &items)
{
    int i = 1;
    while (number > 2 * i) {
        number -= i;
        items.push_back(i);
        ++i;
    }
    if (number > 0) {
        items.push_back(number);
    }

    return items;
}

int main()
{
    int number;
    std::cin >> number;

    std::vector<int> items;
    items = get_various_terms(number, items);

    cout << items.size() << endl;
    for (auto item : items) {
        std::cout << item << " ";
    }
    cout << endl;
    return 0;
}

