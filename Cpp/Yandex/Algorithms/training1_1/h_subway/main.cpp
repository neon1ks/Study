#include <algorithm>
#include <iostream>
#include <utility>


using namespace std;

pair<int, int> algorithm(int a, int b, int n, int m)
{
    int time_min_a = a * (n - 1) + n;
    int time_max_a = time_min_a + 2 * a;

    int time_min_b = b * (m - 1) + m;
    int time_max_b = time_min_b + 2 * b;

    if (time_min_a > time_max_b || time_min_b > time_max_a) {
        return { -1, -1 };
    }

    return { max(time_min_a, time_min_b), min(time_max_a, time_max_b) };


}


int main()
{
    int a = { 0 };
    int b = { 0 };
    int n = { 0 };
    int m = { 0 };

    cin >> a >> b >> n >> m;

    auto result = algorithm(a, b, n, m);

    if (result.first == -1) {
        cout << result.first << endl;
    } else {
        cout << result.first << ' ' << result.second << endl;
    }

    return 0;
}
