#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

int main()
{

    size_t countLines{};
    size_t countPoints{};
    cin >> countLines >> countPoints;

    std::vector<int> LineBegins;
    std::vector<int> LineEnds;
    LineBegins.resize(countLines);
    LineEnds.resize(countLines);
    std::vector<int> points;
    points.resize(countPoints);

    for (size_t i = 0; i < countLines; ++i) {
        cin >> LineBegins[i] >> LineEnds[i];
    }
    for (auto &point : points) {
        cin >> point;
    }

    std::sort(LineBegins.begin(), LineBegins.end());
    std::sort(LineEnds.begin(), LineEnds.end());

    for (auto &point : points) {

        //auto it_lower = std::lower_bound(LineBegins.cbegin(), LineBegins.cend(),
        //        point, [](int value, int point) { return value <= point; });
        //auto it_upper = std::upper_bound(LineEnds.begin(), LineEnds.end(),
        //        point, [](int value, int point) { return value <= point; });

        auto less = std::lower_bound(LineEnds.begin(), LineEnds.end(), point)
                    - LineEnds.begin();
        auto greater =
                std::upper_bound(LineBegins.begin(), LineBegins.end(), point)
                - LineBegins.begin();

        //size_t i_start = static_cast<size_t>(it_lower - LineBegins.cbegin());
        //size_t i_end = static_cast<size_t>(it_upper - LineEnds.cbegin());

        //cout << i_start - i_end << ' ';

        cout << greater - less << " ";
    }
    cout << endl;

    return 0;
}
