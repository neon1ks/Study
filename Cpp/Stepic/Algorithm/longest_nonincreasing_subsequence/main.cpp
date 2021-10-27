#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned N = {};
    cin >> N;
    vector<int> A(N);
    for (auto &n : A) {
        cin >> n;
    }
    vector<unsigned> D(N);
    vector<unsigned> prev(N);
    for (unsigned i = 0; i < N; ++i) {
        D[i] = 1;
        prev[i] = 0;
        for (unsigned j = 0; j < i; ++j) {
            if (A[j] >= A[i] && D[j] + 1 > D[i]) {
                D[i] = D[j] + 1;
                prev[i] = j + 1;
            }
        }
    }
    unsigned maxD = 0;
    unsigned index = 0;
    for (unsigned i = 0; i < N; ++i) {
        if (maxD < D[i]) {
            maxD = D[i];
            index = i + 1;
        }
    }
    cout << maxD << endl;
    // cout << "DTest: index = " << index << endl;

    vector<unsigned> answer(maxD);
    for (unsigned i = 0; i < maxD; ++i) {
        answer[maxD - 1 - i] = index;
        index = prev[index - 1];
    }

    bool first = true;
    for (const auto &a : answer) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << a;
    }
    cout << endl;

    return 0;
}
