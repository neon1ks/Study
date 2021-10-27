#include <numeric>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

int algorithm(const vector<int> &array)
{
    long long min = { 0 };
    // for (auto &e : array) {
    //     min += e;
    // }
    min = std::accumulate(array.begin(), array.end(), min);
    long long ost_temp = min % static_cast<long long>(array.size());
    double ost =
            static_cast<double>(ost_temp) / static_cast<double>(array.size());
    cout << ost << endl;
    min /= static_cast<long long>(array.size());
    return static_cast<int>(min + lround(ost));
}

int algorithm2(const vector<int> &array)
{

    size_t mid = array.size() / 2;
    size_t plus = array.size() % 2;

    if (plus == 1) {
        return array[mid];
    }
    return array[mid - 1] + (array[mid] - array[mid - 1]) / 2;
}

int wrap_algorithm(istream &in, ostream &out)
{
    try {
        size_t n = {};
        in >> n;
        vector<int> array(n);
        for (auto &e : array) {
            in >> e;
        }
        int result = algorithm2(array);
        out << result << endl;
    } catch (...) {
        return -1;
    }
    return 0;
}

int main()
{
    return wrap_algorithm(cin, cout);
}
