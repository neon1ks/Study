#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> numbers = {};
    int number = {};

    while (cin >> number) {
        auto result = numbers.insert(number);
        if (result.second) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
