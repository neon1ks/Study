#include <iostream>
#include <limits>

using namespace std;

int main()
{
    unsigned long long A = {};
    unsigned long long K = {};
    unsigned long long B = {};
    unsigned long long M = {};
    unsigned long long X = {};
    cin >> A >> K >> B >> M >> X;

    unsigned long long start = 0;
    unsigned long long finish = X;

    while (start < finish) {
        unsigned long long m = start + (finish - start) / 2;
        unsigned long long cut1 = (m - m / K) * A;
        unsigned long long cut2 = (m - m / M) * B;
        if (cut1 >= X || cut2 >= X - cut1) {
            finish = m;
        } else {
            start = m + 1;
        }
    }
    cout << start << endl;

    return 0;
}
