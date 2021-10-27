#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    size_t n{};
    size_t m{};
    cin >> n >> m;
    vector<int> numbers(n);
    for (auto &number : numbers) {
        cin >> number;
    }
    vector<pair<int, int>> lines(m);

    vector<pair<int, unsigned>> left_of_lines(m);
    vector<pair<int, unsigned>> right_of_lines(m);

    vector<unsigned> left_pre_sum(m);
    vector<unsigned> right_pre_sum(m);

    for (size_t i = 0; i < m; ++i) {
        cin >> lines[i].first >> lines[i].second;
        left_of_lines[i] = { lines[i].first, i };
        right_of_lines[i] = { lines[i].second, i };
    }

    sort(numbers.begin(), numbers.end());
    sort(left_of_lines.begin(), left_of_lines.end());
    sort(right_of_lines.begin(), right_of_lines.end());

    unsigned left_index = 0;
    for (const auto & point: left_of_lines) {
        while (left_index < numbers.size()
                && numbers[left_index] < point.first) {
            ++left_index;
        }
        left_pre_sum[point.second] = left_index;
    }

    unsigned right_index = 0;
    for (const auto & point: right_of_lines) {
        while (right_index < numbers.size()
                && numbers[right_index] <= point.first) {
            ++right_index;
        }
        right_pre_sum[point.second] = right_index;
    }

    bool first = true;
    for (size_t i = 0; i < lines.size(); ++i) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << right_pre_sum[i] - left_pre_sum[i];
    }
    cout << endl;

    return 0;
}
