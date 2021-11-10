#include <iostream>

using namespace std;

int main()
{
    int now = { 0 };
    int count = { 0 };
    int maximum = { 0 };

    cin >> now;
    if (now != 0) {
        maximum = now;
        count = 1;
        cin >> now;
    }
    while (now != 0) {
        if (now > maximum) {
            maximum = now;
            count = 1;
        } else if (now == maximum) {
            ++count;
        }
        cin >> now;
    }
    cout << count << endl;

    return 0;
}
