#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int algorithm(int n, int k, int m)
{
    if (m > k) {
        return 0;
    }

    int result = { 0 };
    const int step = k / m;
    const int remainder = k % m;
    while (n >= k) {
        n -= k;
        result += step;
        n += remainder;
    }
    return result;
}

#ifdef ONLY_HOME
#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

template<class T>
ostream &operator<<(ostream &os, const set<T> &s)
{
    os << "{";
    bool first = true;
    for (const auto &x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template<class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m)
{
    os << "{";
    bool first = true;
    for (const auto &kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint)
{
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
        throw runtime_error(os.str());
    }
}

inline void Assert(bool b, const string &hint)
{
    AssertEqual(b, true, hint);
}

class TestRunner
{
public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string &test_name)
    {
        try {
            func(test_name);
            cerr << test_name << " OK" << endl;
        } catch (runtime_error &e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

void TestOne(const string &hint)
{
    int n = { 10 };
    int k = { 5 };
    int m = { 2 };
    int expected = { 4 };
    int result = algorithm(n, k, m);
    AssertEqual(expected, result, hint);
}

void TestTwo(const string &hint)
{
    int n = { 13 };
    int k = { 5 };
    int m = { 3 };
    int expected = { 3 };
    int result = algorithm(n, k, m);
    AssertEqual(expected, result, hint);
}

void TestThree(const string &hint)
{
    int n = { 14 };
    int k = { 5 };
    int m = { 3 };
    int expected = { 4 };
    int result = algorithm(n, k, m);
    AssertEqual(expected, result, hint);
}

void TestALL()
{
    TestRunner tr;
    tr.RunTest(TestOne, "Test1");
    tr.RunTest(TestTwo, "Test2");
    tr.RunTest(TestThree, "Test3");
}
#endif

int main()
{
#ifdef ONLY_HOME
    TestALL();
#endif

    int n = { 0 };
    int k = { 0 };
    int m = { 0 };
    cin >> n >> k >> m;

    int result = algorithm(n, k, m);

    cout << result << endl;

    return 0;
}
