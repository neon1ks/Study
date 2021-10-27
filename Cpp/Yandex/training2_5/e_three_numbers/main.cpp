#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    unsigned S = {};
    cin >> S;

    unsigned a_len = {};
    cin >> a_len;
    vector<pair<unsigned, unsigned>> a(a_len);
    for (unsigned i = 0; i < a_len; ++i) {
        unsigned number = {};
        cin >> number;
        a[i] = { number, i };
    }

    unsigned b_len = {};
    cin >> b_len;
    vector<pair<unsigned, unsigned>> b(b_len);
    for (unsigned i = 0; i < b_len; ++i) {
        unsigned number = {};
        cin >> number;
        b[i] = { number, i };
    }

    unsigned c_len = {};
    cin >> c_len;
    vector<pair<unsigned, unsigned>> c(c_len);
    for (unsigned i = 0; i < c_len; ++i) {
        unsigned number = {};
        cin >> number;
        c[i] = { number, i };
    }

    sort(c.begin(), c.end());

    vector<unsigned> answer;

    for (unsigned i = 0; i < a_len; ++i) {
        for (unsigned j = 0; j < b_len; ++j) {
            auto result = lower_bound(c.begin(), c.end(),
                    make_pair(S - a[i].first - b[j].first, 0),
                    [](const pair<unsigned, unsigned> &l,
                            const pair<unsigned, unsigned> &r) -> bool {
                        return l.first < r.first;
                    });
            if (result->first == S - a[i].first - b[j].first) {
                answer = { a[i].second, b[j].second, result->second };
                i = a_len;
                j = b_len;
            }
        }
    }

    if (answer.empty()) {
        cout << -1 << endl;
    } else {
        cout << answer[0] << ' ' << answer[1] << ' ' << answer[2]
             << endl;
    }

    return 0;
}
