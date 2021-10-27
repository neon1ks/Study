#include <iostream>
#include <map>

using namespace std;

int main()
{
    size_t N{};
    cin >> N;

    long long a{};
    long long d{};
    map<long long, long long> colors;
    for (size_t i = 0; i < N; ++i) {
        cin >> a >> d;
        colors[a] += d;
    }

    for (const auto &[key, value] : colors) {
        cout << key << ' ' << value << endl;
    }

    return 0;
}
