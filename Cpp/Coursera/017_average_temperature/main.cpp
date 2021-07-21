#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> days(n);
    int average = 0;
    for (auto &d : days) {
        cin >> d;
        average += d;
    }
    average /= n;

    vector<int> warm_days;
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

/*
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> temperatures(n);
    int sum = 0;
    for (int& temperature : temperatures) {
        cin >> temperature;
        sum += temperature;
    }

    int average = sum / n;
    vector<int> result_indices;
    for (int i = 0; i < n; ++i) {
        if (temperatures[i] > average) {
            result_indices.push_back(i);
        }
    }

    cout << result_indices.size() << endl;
    for (int result_index : result_indices) {
        cout << result_index << " ";
    }
    cout << endl;

    return 0;
}
*/
