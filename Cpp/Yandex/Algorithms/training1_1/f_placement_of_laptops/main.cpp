#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

struct Rectangle
{
    int x = 0;
    int y = 0;
};

bool operator<(const Rectangle &first, const Rectangle &second)
{
    return first.x * first.y < second.x * second.y;
}

bool operator==(const Rectangle &first, const Rectangle &second)
{
    return first.x * first.y == second.x * second.y;
}

bool operator!=(const Rectangle &first, const Rectangle &second)
{
    return first.x * first.y != second.x * second.y;
}

ostream &operator<<(ostream &out, const Rectangle rect)
{
    return out << '(' << rect.x << ',' << rect.y << ')';
}

Rectangle algorithm(Rectangle laptop1, Rectangle laptop2)
{
    array<Rectangle, 4> tables = {};

    tables[0].x = laptop1.x + laptop2.x;
    tables[0].y = max(laptop1.y, laptop2.y);

    tables[1].x = laptop1.x + laptop2.y;
    tables[1].y = max(laptop1.y, laptop2.x);

    tables[2].x = laptop1.y + laptop2.x;
    tables[2].y = max(laptop1.x, laptop2.y);

    tables[3].x = laptop1.y + laptop2.y;
    tables[3].y = max(laptop1.x, laptop2.x);

    Rectangle answer = tables[0];
    for (const auto &table : tables) {
        answer = min(table, answer);
    }
    return answer;
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
    Rectangle laptop1 = { 10, 2 };
    Rectangle laptop2 = { 2, 10 };
    Rectangle expected = { 20, 2 };
    Rectangle result = algorithm(laptop1, laptop2);
    AssertEqual(expected, result, hint);
}

void TestTwo(const string &hint)
{
    Rectangle laptop1 = { 5, 7 };
    Rectangle laptop2 = { 3, 2 };
    Rectangle expected = { 9, 5 };
    Rectangle result = algorithm(laptop1, laptop2);
    AssertEqual(expected, result, hint);
}

void TestALL()
{
    TestRunner tr;
    tr.RunTest(TestOne, "Test1");
    tr.RunTest(TestTwo, "Test2");
}
#endif

int main()
{
#ifdef ONLY_HOME
    TestALL();
#endif

    Rectangle laptop1 = {};
    Rectangle laptop2 = {};

    cin >> laptop1.x >> laptop1.y >> laptop2.x >> laptop2.y;

    Rectangle answer = algorithm(laptop1, laptop2);

    cout << answer.x << ' ' << answer.y << endl;

    return 0;
}
