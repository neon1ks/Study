#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

struct Group
{
    unsigned id;
    unsigned count;
    unsigned room;
};

int main()
{
    unsigned N = {};
    unsigned M = {};
    cin >> N >> M;

    vector<Group> groups(N);
    vector<pair<unsigned, unsigned>> classes(M);

    for (unsigned i = 0; i < N; ++i) {
        unsigned number = {};
        cin >> number;
        groups[i] = { i, number, 0 };
    }

    for (unsigned i = 0; i < M; ++i) {
        unsigned number = {};
        cin >> number;
        classes[i] = { number, i + 1 };
    }

    sort(groups.begin(), groups.end(),
            [](const Group &l, const Group &r) -> bool {
                return l.count < r.count;
            });
    sort(classes.begin(), classes.end());

    unsigned group_index = 0;
    for (unsigned i = 0; i < M; ++i) {
        if (group_index < N && classes[i].first > groups[group_index].count) {
            groups[group_index].room = classes[i].second;
            ++group_index;
        }
    }

    sort(groups.begin(), groups.end(),
            [](const Group &l, const Group &r) -> bool { return l.id < r.id; });

    cout << group_index << endl;
    bool first = true;
    for (const auto &group : groups) {
        if (first) {
            first = false;
        } else {
            cout << ' ';
        }
        cout << group.room;
    }
    cout << endl;

    return 0;
}
