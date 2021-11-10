#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a;
    string b;
    string c;
    cin >> a >> b >> c;
    if (a < b) {
        if (a < c) {
            cout << a;
        } else {
            cout << c;
        }
    } else {
        if (b < c) {
            cout << b;
        } else {
            cout << c;
        }
    }
    cout << endl;

    return 0;
}

/*
#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    if (a <= b && a <= c) {
        cout << a;
    } else if (b <= a && b <= c) {
        cout << b;
    } else {
        cout << c;
    }
    return 0;
}
*/
