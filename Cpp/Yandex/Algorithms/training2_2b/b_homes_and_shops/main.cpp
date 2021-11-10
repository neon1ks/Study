#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const int COUNT = 10;

int main()
{
    array<int, COUNT> builds = {};
    for (auto &b : builds) {
        cin >> b;
    }
    size_t maximum = { 0 };
    for (size_t i = 0; i < builds.size(); ++i) {
        if (builds.at(i) == 1) {
            size_t min1 = 0;
            size_t min2 = 0;
            bool flag1 = false;
            bool flag2 = false;
            size_t j = i;
            while (j > 0) {
                --j;
                if (builds.at(j) == 2) {
                    flag1 = true;
                    min1 = i - j;
                    break;
                }
            }
            j = i;
            while (j < builds.size() - 1) {
                ++j;
                if (builds.at(j) == 2) {
                    flag2 = true;
                    min2 = j - i;
                    break;
                }
            }
            if (flag1 && flag2) {
                maximum = max(maximum, min(min1, min2));
            } else if (flag1) {
                maximum = max(maximum, min1);
            }else if (flag2) {
                maximum = max(maximum, min2);
            }
        }
    }
    cout << maximum << endl;

    return 0;
}
