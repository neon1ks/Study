#include <iostream>
#include <vector>
#include <deque>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

template<typename T>
void merge_sort(
        std::deque<std::vector<T>> &data, size_t &inversionCount) noexcept
{
    while (data.size() > 1) {

        bool copyLast = data.size() % 2;
        size_t countPair = data.size() / 2;
        for (size_t i = 0; i < countPair; ++i) {
            auto &left = data[0];
            auto &right = data[1];

            //cout << '[';
            //for (const auto &n : left) {
            //    cout << n << ' ';
            //}
            //cout << "]  [";
            //for (const auto &n : right) {
            //    cout << n << ' ';
            //}
            //cout << ']' << endl;

            size_t i_left = 0;
            size_t i_right = 0;

            std::vector<T> merged;
            merged.reserve(left.size() + right.size());

            while (i_left < left.size() && i_right < right.size()) {
                if (left[i_left] <= right[i_right]) {
                    merged.push_back(left[i_left]);
                    ++i_left;
                } else {
                    size_t diff = left.size() - i_left;
                    inversionCount += diff;
                    //cout << "inversionCount += " << diff << endl;
                    merged.push_back(right[i_right]);
                    ++i_right;
                }
            }

            while (i_left < left.size()) {
                merged.push_back(left[i_left]);
                ++i_left;
            }
            while (i_right < right.size()) {
                merged.push_back(right[i_right]);
                ++i_right;
            }

            data.pop_front();
            data.pop_front();
            data.push_back(std::move(merged));
        }
        if (copyLast) {
            auto &right = data[0];
            data.push_back(right);
            data.pop_front();
        }
    }
}

int main()
{
    size_t count{};
    cin >> count;

    std::deque<std::vector<int>> data;

    for (size_t i = 0; i < count; ++i) {
        int temp{};
        cin >> temp;
        data.push_back(std::vector<int>{ temp });
    }

    size_t inversionCount = 0;
    merge_sort(data, inversionCount);

    cout << inversionCount << endl;

    return 0;
}
