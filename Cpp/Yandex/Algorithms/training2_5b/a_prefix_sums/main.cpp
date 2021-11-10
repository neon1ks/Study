#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned n = 0;
    unsigned q = 0;
    cin >> n >> q;
    vector<unsigned long long> pre(n + 1);

    pre[0] = 0;
    for (unsigned index = 1; index <= n; ++index) {
        unsigned number = 0;
        cin >> number;
        pre[index] = pre[index - 1] + number;
    }

    for (unsigned i = 0; i < q; ++i) {
        unsigned l = 0;
        unsigned r = 0;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }

    return 0;
}
