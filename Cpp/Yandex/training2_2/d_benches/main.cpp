#include <iostream>
#include <vector>

using namespace std;

int main()
{
    size_t length = { 0 };
    size_t count = { 0 };
    cin >> length >> count;

    vector<size_t> places(count, 0);
    for (auto &i : places) {
        cin >> i;
    }
    bool has_center = false;
    size_t center_left = 0;
    size_t center_right = 0;

    if (length % 2 == 1) {
        center_right = center_left = length / 2;
        for (auto i : places) {
            if (i == center_left) {
                has_center = true;
                break;
            }
        }
    } else {
        center_right = length / 2;
        center_left = center_right - 1;
    }
    if (has_center) {
        cout << center_right << endl;
    } else {
        size_t left = places[0];
        size_t right = places[places.size() - 1];
        for (auto i : places) {
            if (i <= center_left) {
                left = i;
            }
            if (i >= center_right) {
                right = i;
                break;
            }
        }
        cout << left << ' ' << right << endl;
    }

    return 0;
}
