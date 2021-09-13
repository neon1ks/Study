#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
    size_t n = 0;
    cin >> n;
    vector<int> days(n);
    int64_t average = 0;
    for (auto &d : days) {
        cin >> d;
        average += d;
    }
    average /= static_cast<int64_t>(n);

    vector<unsigned> warm_days;
    for (size_t i = 0; i < days.size(); ++i) {
        if (days[i] > average) {
            warm_days.push_back(i);
        }
    }

    cout << warm_days.size() << endl;
    for (auto &d : warm_days) {
        cout << d << ' ';
    }
    cout << endl;

    return 0;
}
