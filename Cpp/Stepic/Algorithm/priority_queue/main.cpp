#include <iostream>
#include <string>
#include <vector>
#include <queue>

int main()
{
    int count;
    std::cin >> count;
    std::cin.get();

    std::vector<std::string> list;
    list.resize(count);
    for (int i = 0; i < count; ++i) {
        std::getline(std::cin, list[i]);
    }

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return left < right; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> queue(cmp);

    //std::priority_queue<int> queue;

    for (int i = 0; i < count; ++i) {
        if (list[i] == "ExtractMax") {
            std::cout << queue.top() << std::endl;
            queue.pop();
        } else {
            int elem = std::stoi(list[i].substr(7, list[i].size()));
            queue.push(elem);
        }
    }

    return 0;
}
