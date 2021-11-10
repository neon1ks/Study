#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    size_t N = {};
    cin >> N;
    vector<pair<int, int>> lines(N);
    for (auto &l : lines) {
        cin >> l.first >> l.second;
    }
    sort(lines.begin(), lines.end());

    int line_finish = lines[0].first;
    int sum = 0;
    for (const auto &[start, finish] : lines) {
        if (start <= line_finish) {
            if (finish > line_finish) {
                sum += finish - line_finish;
                line_finish = finish;
            }
        } else {
            sum += finish - start;
            line_finish = finish;
        }
    }

    cout << sum << endl;
    return 0;
}
