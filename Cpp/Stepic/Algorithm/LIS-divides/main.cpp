#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t N = {};
    cin >> N;
    vector<int> A(N);
    for (auto &n : A) {
        cin >> n;
    }
    vector<int> D(N);
    for (size_t i = 0; i < N; ++i) {
        D[i] = 1;
        for (size_t j = 0; j < i; ++j) {
            if (A[j] <= A[i] && D[j] + 1 > D[i] && A[i] % A[j] == 0) {
                D[i] = D[j] + 1;
            }
        }
    }
    int ans = 0;
    for (auto d : D) {
        ans = max(ans, d);
    }
    cout << ans << endl;

    return 0;
}
