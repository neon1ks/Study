#include <iostream>
#include <cmath>

using namespace std;

constexpr double Zero = 0.000000000001;

int main()
{

    double a;
    double b;
    double c;
    cin >> a >> b >> c;

    if (abs(a) > Zero) {
        double d = sqrt(b * b - 4 * a * c);
        if (d > 0) {
            double x1 = (-b + d) / (2 * a);
            double x2 = (-b - d) / (2 * a);
            cout << x1 << ' ' << x2;
        } else if (abs(d) <= Zero) {
            double x = (-b) / (2 * a);
            cout << x;
        } else {
        }
    } else if (abs(b) > Zero) {
        double x = (-c) / b;
        cout << x;
    }
    cout << endl;
    return 0;
}

/*
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A, B, C;
    cin >> A >> B >> C;

    // найдём дискриминант
    double D = B * B - 4 * A * C;

    // если A равно нулю, то уравнение линейное: Bx + C = 0
    if (A == 0) {

        // Bx = -C => x = -C / B
        if (B != 0) {
            cout << -C / B << endl;
        }
        // если B равно нулю, корней нет

    } else if (D == 0) {  // случай с нулевым дискриминантом

        // корень ровно один
        cout << -B / (2 * A) << endl;

    } else if (D > 0) {  // в случае с положительным дискриминантом корня два

        double r1 = (-B + sqrt(D)) / (2 * A);
        double r2 = (-B - sqrt(D)) / (2 * A);

        cout << r1 << " " << r2 << endl;

    }
    // если дискриминант отрицателен, действительных корней нет

    return 0;
}
*/
