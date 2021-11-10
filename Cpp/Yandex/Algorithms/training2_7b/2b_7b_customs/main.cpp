#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    size_t N{};
    cin >> N;
    vector<pair<int, int>> data(2 * N);

    for (size_t i = 0; i < N; ++i) {
        int t{};
        int p{};
        cin >> t >> p;
        data[i * 2] = { t, 1 };
        data[i * 2 + 1] = { t + p, -1 };
    }

    sort(data.begin(), data.end());

    int maxcount{};
    int count{};
    for (const auto &d : data) {
        count += d.second;
        maxcount = max(maxcount, count);
    }

    cout << maxcount << endl;
    return 0;
}
