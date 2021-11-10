#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;

    cin >> a >> b;

    if (a % 2 != 0) {
        ++a;
    }
    for (int i = a; i <= b; i += 2) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

/*
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (i % 2 == 0) {
            cout << i << ' ';
        }
    }
    return 0;
}
*/
