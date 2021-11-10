#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool algorithm(int a, int b, int c, int d, int e)
{
    vector<int> brick = { a, b, c };
    sort(brick.begin(), brick.end());
    int first = max(d, e);
    int second = min(d, e);
    return (brick[1] <= first && brick[0] <= second);
}

int main()
{
    int a = { 0 };
    int b = { 0 };
    int c = { 0 };
    int d = { 0 };
    int e = { 0 };
    cin >> a >> b >> c >> d >> e;
    cout << (algorithm(a, b, c, d, e) ?"YES" : "NO") << endl;
    return 0;
}
