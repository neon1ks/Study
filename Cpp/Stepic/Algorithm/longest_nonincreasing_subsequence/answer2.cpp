#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;


unsigned lnis(const std::vector<int> &A, std::vector<unsigned> &answer)
{
    auto N = static_cast<unsigned>(A.size());
    int inf = abs(*max_element(A.begin(), A.end(),
                      [](const int &l, const int &r) -> bool {
                          return abs(l) < abs(r);
                      }))
              + 1;

    std::vector<int> L(N + 2, -inf);
    L[0] = +inf;
    std::vector<std::set<unsigned>> M(N + 2);

    for (unsigned i = 0; i < N; ++i) {
        unsigned left = 0;
        unsigned right = N + 1;
        while (left + 1 < right) {
            unsigned middle = (left + right) / 2;
            if (L[middle] > A[i] - 1) {
                left = middle;
            } else {
                right = middle;
            }
        }
        L[right] = A[i];
        M[right].insert(i);
    }

    unsigned index = N + 1;
    while (L[index] == -inf) {
        index -= 1;
    }

    auto now_i = static_cast<unsigned>(index);
    for (unsigned t = N; t > 0; --t) {
        unsigned i = t - 1;
        if (M[now_i].count(i) == 1) {
            --now_i;
            answer.emplace_back(i + 1);
        }
    }
    reverse(answer.begin(), answer.end());
    return index;
}

int main()
{
    unsigned N = {};
    cin >> N;
    vector<int> A(N);
    for (auto &n : A) {
        cin >> n;
    }

    std::vector<unsigned> answer;
    unsigned m = lnis(A, answer);
    cout << m << endl;
    bool first = true;
    for (const auto a : answer) {
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
