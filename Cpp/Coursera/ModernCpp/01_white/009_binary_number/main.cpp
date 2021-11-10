#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    vector<bool> b;
    cin >> n;
    while (n > 0) {
        b.push_back(n % 2 == 1);
        n /= 2;
    }
    for (size_t i = b.size(); i > 0; --i) {
        cout << (b[i - 1] ? '1' : '0');
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
    vector<int> bits;

    cin >> n;
    while (n > 0) {
        bits.push_back(n % 2);
        n /= 2;
    }

    for (int i = bits.size() - 1; i >= 0; --i) {
        cout << bits[i];
    }
    return 0;
}
*/
