#include <iostream>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::size_t;

int main() {
    size_t count{};
    cin >> count;
    
    std::map<int, int> a;
    for (size_t i = 0; i < count; ++i) {
        int temp{};
        cin >> temp;
        ++a[temp];
    }
    const size_t max = 10;
    for (size_t i = 0; i <= max; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}
