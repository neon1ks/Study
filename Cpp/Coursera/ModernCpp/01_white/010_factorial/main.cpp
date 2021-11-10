#include <iostream>

using namespace std;

int Factorial(int x)
{
    int result = 1;
    while (x > 0) {
        result *= x;
        --x;
    }
    return result;
}

int main()
{
    int number = 0;
    cin >> number;
    cout << Factorial(number) << endl;
    return 0;
}

/*
int Factorial(int x) {
  int result = 1;
  for (int i = 2; i <= x; ++i) {
    result *= i;
  }
  return result;
}

int Factorial(int x) {
    if (x <= 1) {
        return 1;
    } else {
        return x * Factorial(x - 1);  // вычисляем факториал от x-1 и умножаем на x
    }
}
*/
