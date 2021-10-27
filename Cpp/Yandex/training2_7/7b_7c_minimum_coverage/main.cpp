#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
#include <tuple>

using namespace std;

//struct ResultLine
//{
//    unsigned id;
//    int start;
//    int finish;
//    bool operator < (const ResultLine& other) const {
//        return std::tie(id, start, finish)
//               < std::tie(other.id, other.start, other.finish);
//    }
//};
//
//struct Line
//{
//    int start;
//    int finish;
//    unsigned id;
//    bool operator < (const Line& other) const {
//        return std::tie(start, finish, id)
//               < std::tie(other.start, other.finish, other.id);
//    }
//    // bool operator<(const Line &other) const
//    // {
//    //     if (start == other.start) {
//    //         return finish > other.finish;
//    //     }
//    //     return start < other.start;
//    // }
//};

int main()
{
    int M{};
    cin >> M;
    vector<pair<int, int>> lines;

    int start{};
    int finish{};
    cin >> start >> finish;
    while (start != 0 || finish != 0) {
        lines.emplace_back(start, finish);
        cin >> start >> finish;
    }

    sort(lines.begin(), lines.end());

    vector<pair<int, int>> result;
    pair<int, int> now{};

    int line_end = 0;
    bool flag = true;
    for (const auto &l : lines) {
        if (l.first > line_end) {
            if (l.first > now.second) {
                // Разрыв, выходим
                flag = false;
                break;
            }
            line_end = now.second;
            result.push_back(now);
            if (now.second >= M) {
                flag = true;
                break;
            }
        }
        if (now.second < l.second) {
            now = l;
        }
    }

    if (line_end < M) {
        if (now.second >= M) {
            result.push_back(now);
            flag = true;
        } else {
            flag = false;
        }
    }

    if (flag) {
        cout << result.size() << endl;
        //sort(result.begin(), result.end());
        for (const auto &r : result) {
            cout << r.first << ' ' << r.second << endl;
        }
    } else {
        cout << "No solution" << endl;
    }

    return 0;
}
