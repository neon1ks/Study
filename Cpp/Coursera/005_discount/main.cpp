#include <iostream>

using namespace std;

int main()
{
    double n = 0.;
    double a = 0.;
    double b = 0.;
    double x = 0.;
    double y = 0.;

    cin >> n >> a >> b >> x >> y;

    if (n > b) {
        cout << n * (100. - y) / 100. << endl;
    } else if (n > a) {
        cout << n * (100. - x) / 100. << endl;
    } else {
        cout << n << endl;
    }

    return 0;
}

/*
#include <iostream>

using namespace std;

int main() {
    double n, a, b, x, y;
    cin >> n >> a >> b >> x >> y;
    if (n > b) {
        n *= (1 - y / 100);
    } else if (n > a) {
        n *= (1 - x / 100);
    }
    cout << n;

    return 0;
}
*/
