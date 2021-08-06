#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    const string file_name = "input.txt";
    ifstream input(file_name);
    if (input) {
        double number = 0;
        while (input >> number) {
            cout << fixed << setprecision(3) << number << endl;
        }
    }
    return 0;
}

/*
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    double a;

    cout << fixed << setprecision(3);

    while (input >> a) {
        cout << a << endl;
    }

    return 0;
}
*/
