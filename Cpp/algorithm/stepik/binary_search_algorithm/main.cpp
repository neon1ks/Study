#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::size_t;
using std::string;

int get_pos1(const std::vector<int> &numbers, int number)
{
    auto it = std::find(numbers.begin(), numbers.end(), number);
    if (it == numbers.end()) {
        return -1;
    }
    return static_cast<int>(it - numbers.begin()) + 1;
}

int get_pos2(const std::vector<int> &numbers, int number)
{
    auto it = std::lower_bound(numbers.begin(), numbers.end(), number);
    if (it == numbers.end() || *it != number) {
        return -1;
    }
    return static_cast<int>(it - numbers.begin()) + 1;
}
size_t BSearch3(const std::vector<int> &numbers, int number)
{
    if (numbers.empty()) {
        return 0;
    }

    size_t l = 0;
    size_t r = numbers.size();
    while (l + 1 < r) {

        cout << '[';
        for (size_t i = l; i < r; ++i) {
            cout << numbers[i] << ' ';
        }
        cout << ']';

        size_t m = l + (r - l) / 2;
        cout << "; m = " << m;

        if (numbers[m] > number) {
            r = m;
        } else {
            l = m;
        }
        cout << "; new l = " << l << ", r = " << r << endl;
    }
    if (l == r || numbers[l] != number) {
        return numbers.size();
    }
    return l;
}

size_t BSearch4(const std::vector<int> &numbers, int number)
{
    if (numbers.empty()) {
        return 0;
    }

    size_t l = 0;
    size_t r = numbers.size() - 1;
    while (l < r) {

        //cout << '[';
        //for (size_t i = l; i <= r; ++i) {
        //    cout << numbers[i] << ' ';
        //}
        //cout << ']';

        size_t m = l + (r - l) / 2;
        //cout << "; m = " << m;

        if (numbers[m] >= number) {
            r = m;
        } else {
            l = m + 1;
        }
        //cout << "; new l = " << l << ", r = " << r << endl;
    }
    if (numbers[l] != number) {
        return numbers.size();
    }
    return l;
}

// Если last = true, возвращает индекс на элемент после последнего найденного
int bsearch(const std::vector<int> &a, int k, bool last = false)
{
    int l = 0;
    int r = static_cast<int>(a.size() - 1);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (k > a[mid] || (k == a[mid] && last)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main()
{

    std::size_t number_count{};
    //cout << "Number count: ";
    std::cin >> number_count;
    std::vector<int> numbers(number_count);

    // cout << "Numbers: ";
    for (auto &number : numbers) {
        std::cin >> number;
    }
    std::sort(numbers.begin(), numbers.end());
    assert(std::is_sorted(numbers.begin(), numbers.end()));

    std::size_t query_count{};
    //cout << "Query count: ";
    std::cin >> query_count;

    std::vector<int> findNumbers(query_count);
    //cout << "Find Numbers: ";
    for (auto &number : findNumbers) {
        std::cin >> number;
    }

    //cout << "result" << endl;
    for (auto &number : findNumbers) {
        auto res = BSearch4(numbers, number);
        if (res == numbers.size()) {
            cout << -1 << ' ';
        } else {
            cout << res << ' ';
        }
    }
    std::cout << std::endl;

    for (auto &number : findNumbers) {
        cout << bsearch(numbers, number) << ' ';
    }
    std::cout << std::endl;

    for (auto &number : findNumbers) {
        cout << bsearch(numbers, number, true) << ' ';
    }
    std::cout << std::endl;
    return 0;
}
