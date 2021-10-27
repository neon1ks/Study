#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int algorithm(int a, int b, int c)
{
    if ((a < 13 && b >= 13 && c >= 1970) || (a >= 13 && b < 13 && c >= 1970)
            || (a < 13 && b < 13 && a == b && c >= 1970)) {
        return 1;
    }
    return 0;
}

int wrap_algorithm(istream &in, ostream &out)
{
    try {
        int a = {};
        int b = {};
        int c = {};
        in >> a >> b >> c;
        int result = algorithm(a, b, c);
        out << result << endl;
    } catch (...) {
        return -1;
    }
    return 0;
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
    TestRunner() = default;
    TestRunner(const TestRunner &) = delete;
    TestRunner &operator=(const TestRunner &) = delete;
    TestRunner(TestRunner &&) = delete;
    TestRunner &operator=(TestRunner &&) = delete;

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
    int fail_count{ 0 };
};

void TestOne(const string &hint)
{
    int a = { 1 };
    int b = { 2 };
    int c = { 2003 };
    int expected = { 0 };
    int result = algorithm(a, b, c);
    AssertEqual(expected, result, hint);
}

void TestTwo(const string &hint)
{
    int a = { 2 };
    int b = { 29 };
    int c = { 2008 };
    int expected = { 1 };
    int result = algorithm(a, b, c);
    AssertEqual(expected, result, hint);
}

void TestThree(const string &hint)
{
    int a = { 3 };
    int b = { 3 };
    int c = { 2067 };
    int expected = { 1 };
    int result = algorithm(a, b, c);
    AssertEqual(expected, result, hint);
}

void TestFour(const string &hint)
{
    int a = { 10 };
    int b = { 12 };
    int c = { 2001 };
    int expected = { 0 };
    int result = algorithm(a, b, c);
    AssertEqual(expected, result, hint);
}

void TestALL()
{
    TestRunner tr;
    tr.RunTest(TestOne, "Test1");
    tr.RunTest(TestTwo, "Test2");
    tr.RunTest(TestThree, "Test3");
    tr.RunTest(TestFour, "Test16");
}
#endif

int main()
{
#ifdef ONLY_HOME
    TestALL();
#endif
    return wrap_algorithm(cin, cout);
}
