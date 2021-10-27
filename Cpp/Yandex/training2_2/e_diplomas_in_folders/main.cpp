#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
    size_t count = { 0 };
    cin >> count;
    vector<size_t> sizes(count, 0);
    for (auto &s : sizes) {
        cin >> s;
    }
    sort(sizes.begin(), sizes.end());

    size_t sum = { 0 };
    sum =  accumulate(sizes.begin(), sizes.end() - 1, sum);
    // for (size_t i = 0; i < sizes.size() - 1; ++i) {
    //     sum += sizes[i];
    // }
    cout << sum << endl;
    return 0;
}
