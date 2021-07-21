#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int> &v)
{
    size_t n = v.size() / 2;
    for (size_t i = 0; i < n; ++i) {
        int temp = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = temp;
    }
}

int main()
{
    vector<int> numbers = { 1, 5, 3, 4, 2 };
    Reverse(numbers);
    for (auto i : numbers) {
        cout << i << ' ';
    }
    return 0;
}

/*
void Reverse(vector<int>& v) {
  int n = v.size();  // для удобства сохраним размер вектора в переменную n
  for (int i = 0; i < n / 2; ++i) {
    // элемент с индексом i симметричен элементу с индексом n - 1 - i
    // поменяем их местами с помощью временной переменной tmp
    int tmp = v[i];
    v[i] = v[n - 1 - i];
    v[n - 1 - i] = tmp;
  }
}
*/
