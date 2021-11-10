#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    unsigned n = 0;
    cin >> n;

    vector<long long> pre(n + 1);

    int number = 0;
    cin >> number;
    long long maximum = { number };
    pre[0] = 0;
    pre[1] = number;
    unsigned start = 0;
    if (number < 0) {
        start = 1;
    }

    for (unsigned i = 1; i < n; ++i) {
        cin >> number;
        pre[i + 1] = pre[i] + number;
        long long sum = pre[i + 1] - pre[start];
        maximum = max(maximum, sum);
        if (sum < 0) {
            start = i + 1;
        }
    }

    cout << maximum << endl;

    return 0;
}
