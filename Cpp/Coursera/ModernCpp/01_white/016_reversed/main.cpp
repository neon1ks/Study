#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int> &v)
{
    vector<int> result(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        result[i] = v[v.size() - 1 - i];
    }
    return result;
}

int main()
{
    vector<int> numbers = { 1, 5, 3, 4, 2 };
    auto result = Reversed(numbers);
    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;
    return 0;
}

/*
vector<int> Reversed(const vector<int>& input)
{
    vector<int> result;
    for (int i = input.size() - 1; i >= 0; --i) {
        result.push_back(input[i]);
    }
    return result;
}
*/
