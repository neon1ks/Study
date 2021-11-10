#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cin >> a >> b;
    if (b == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << a / b << endl;
    }
    return 0;
}

/*
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b == 0) {
        cout << "Impossible" << endl;
    } else {
        cout << a / b << endl;
    }

    return 0;
}
*/
