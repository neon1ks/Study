#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool check(const vector<long long> &numbers, size_t k, long long l)
{
    size_t step = 0;
    auto it = numbers.begin();
    while (it != numbers.end()) {
        long long find = *it + l;
        it = upper_bound(numbers.begin(), numbers.end(), find);
        ++step;
        //cout << "step = " << step << ", l = " << l << endl;
    }
    return step <= k;
}

int main()
{
    size_t n, k = {};
    //size_t k = {};
    cin >> n >> k;

    int test1 = 8;
    int *test = &test1;
    cout << *test << endl;

    //cout << "n = " << n << endl;
    //cout << "k = " << k << endl;

    vector<long long> numbers(n);
    for (auto &number : numbers) {
        cin >> number;
    }
    sort(numbers.begin(), numbers.end());

    long long minimum = numbers[0];
    long long maximum = numbers[n - 1];
    //cout << "min_element = " << minimum << endl;
    //cout << "max_element = " << maximum << endl;

    if (numbers.size() <= k) {
        cout << 0 << endl;
        return 0;
    }

    long long l_start = 0;
    long long l_end = (maximum - minimum) / static_cast<long long>(k) + 1;
    while (l_start < l_end) {
        long long l_m = l_start + (l_end - l_start) / 2;
        if (check(numbers, k, l_m)) {
            l_end = l_m;
        } else {
            l_start = l_m + 1;
        }
    }
    cout << l_start << endl;
    return 0;
}
