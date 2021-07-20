#include <iostream>

using namespace std;

long long factorial(long long x)
{
    long long result = 1;
    while (x > 0) {
        result *= x;
        --x;
    }
    return result;
}

int main()
{
    long long number = 0;
    cin >> number;
    cout << factorial(number) << endl;
    return 0;
}
