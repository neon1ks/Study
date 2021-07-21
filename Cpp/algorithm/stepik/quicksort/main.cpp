#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;

size_t Partition(std::vector<int> &data, size_t i_left, size_t i_right)
{
    assert(i_left <= i_right);
    assert(i_right < data.size());

    if (data.size() == 1) {
        return i_left;
    }
    size_t i_work = i_left;

    if (i_right - i_left >= 2) {
        auto i_mid = i_left + (i_right - i_left) / 2;
        cout << data[i_left] << ", " << data[i_mid] << ", " << data[i_right]
             << "; ";
        if (data[i_left] < data[i_mid]) {
            if (data[i_mid] < data[i_right]) {
                i_work = i_mid;
            } else if (data[i_left] < data[i_right]) {
                i_work = i_right;
            } else {
                i_work = i_left;
            }
        } else {
            if (data[i_left] < data[i_right]) {
                i_work = i_left;
            } else if (data[i_mid] < data[i_right]) {
                i_work = i_right;
            } else {
                i_work = i_mid;
            }
        }
        cout << data[i_work] << std::endl;
    }

    int x = data[i_work];
    size_t j = i_left;

    for (size_t i = i_left; i <= i_right; ++i) {
        if (i == i_work) {
            continue;
        }
        if (data[i] <= x) {
            if (j == i_work) {
                ++j;
            }
            if (j != i) {
                std::swap(data[j], data[i]);
            }
            ++j;
        }
    }

    if (i_work < j) {
        std::swap(data[i_work], data[--j]);
    } else if (i_work > j) {
        std::swap(data[i_work], data[j]);
    }

    return j;
}

std::pair<int, int> Partition3(std::vector<int> &v, int l, int r)
{
    int random = l + (rand() % static_cast<int>(r - l + 1));
    std::swap(v[l], v[random]);
    int x = v[l];
    std::pair<int, int> index = { l, l };
    for (int i = l + 1; i <= r; ++i) {
        if (v[i] < x) {
            index.first++;
            index.second++;
            std::swap(v[index.second], v[i]);
            std::swap(v[index.second], v[index.first]);
        } else if (v[i] == x) {
            index.second++;
            std::swap(v[index.second], v[i]);
        }
    }
    std::swap(v[l], v[index.first]);
    return index;
}

void QuickSort(std::vector<int> &data, size_t i_left, size_t i_right)
{
    if (i_left >= i_right) {
        return;
    }
    auto m = Partition(data, i_left, i_right);
    QuickSort(data, i_left, (m > 0 ? m - 1 : 0));
    QuickSort(data, (m < i_right ? m + 1 : i_right), i_right);
}

void Quick3Sort(std::vector<int> &v, int l, int r)
{
    while (l < r) {
        auto index = Partition3(v, l, r);
        Quick3Sort(v, l, index.first - 1);
        l = index.second + 1;
    }
}

int main()
{
    srand(time(nullptr));
    size_t count{};
    cin >> count;
    std::vector<int> data;
    data.resize(count);
    for (auto &element : data) {
        cin >> element;
    }
    QuickSort(data, 0, data.size() - 1);
    for (auto &element : data) {
        cout << element << ' ';
    }
    cout << endl;
    return 0;
}
