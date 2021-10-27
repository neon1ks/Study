#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned N = {};
    cin >> N;
    vector<int> arr(N);
    for (auto &a : arr) {
        cin >> a;
    }
    sort(arr.begin(), arr.end());

    vector<unsigned> results;
    unsigned K = {};
    cin >> K;
    for (unsigned i = 0; i < K; ++i) {
        int L = {};
        int R = {};
        cin >> L >> R;
        auto it_r = upper_bound(arr.begin(), arr.end(), R);
        auto it_l = lower_bound(arr.begin(), arr.end(), L);
        results.emplace_back(static_cast<unsigned>(it_r - it_l));
    }

    bool first = true;
    for (const auto &r : results) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << r;
    }
    cout << endl;
    return 0;
}
