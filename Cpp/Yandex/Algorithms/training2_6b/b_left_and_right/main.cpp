#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned N = {};
    cin >> N;
    vector<unsigned> arr(N);
    for (auto &a : arr) {
        cin >> a;
    }
    unsigned M = {};
    cin >> M;
    for (unsigned i = 0; i < M; ++i) {
        unsigned number = {};
        cin >> number;
        auto it_l = lower_bound(arr.begin(), arr.end(), number);
        auto it_r = upper_bound(arr.begin(), arr.end(), number);

        unsigned l = 0;
        unsigned r = 0;
        if (it_l != arr.end() && *it_l == number) {
            l = static_cast<unsigned>(it_l - arr.begin() + 1);
            r = static_cast<unsigned>(it_r - arr.begin());
        }
        cout << l << ' ' << r << endl;
    }
    return 0;
}
