#include <algorithm>
#include <iostream>
#include <utility> // Для std::pair
#include <vector>

using Segment = std::pair<int, int>;

std::vector<int> get_covering_set(std::vector<Segment> segments)
{
    std::vector<int> result;

    sort(segments.begin(), segments.end(),
            [](const Segment &a, const Segment &b) -> bool {
                return a.second < b.second;
            });

    int current = -1;
    for (auto s : segments) {
        if (current < s.first) {
            result.push_back(s.second);
            current = s.second;
        }
    }

    return result;
}

int main(void)
{
    int segments_count;
    std::cin >> segments_count;
    std::vector<Segment> segments(segments_count);
    for (auto &s : segments) {
        std::cin >> s.first >> s.second;
    }

    auto points = get_covering_set(std::move(segments));
    std::cout << points.size() << std::endl;
    for (auto point : points) {
        std::cout << point << " ";
    }
    std::cout << std::endl;
}
