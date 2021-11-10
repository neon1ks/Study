#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

[[nodiscard]] constexpr bool qFuzzyCompare(double p1, double p2)
{
    return (std::abs(p1 - p2) * 1000000000000.
            <= std::min(std::abs(p1), std::abs(p2)));
}

[[nodiscard]] constexpr bool qFuzzyCompare(float p1, float p2)
{
    return (std::abs(p1 - p2) * 100000.F
            <= std::min(std::abs(p1), std::abs(p2)));
}

[[nodiscard]] constexpr bool qFuzzyIsNull(double d)
{
    return std::abs(d) <= 0.000000000001;
}

[[nodiscard]] constexpr bool qFuzzyIsNull(float f)
{
    return std::abs(f) <= 0.00001F;
}

template<typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p);

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vi);

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s);

template<typename Key, typename Value>
std::ostream &operator<<(std::ostream &out, const std::map<Key, Value> &m);

template<typename Collection>
std::string Join(const Collection &c, char d)
{
    std::stringstream ss;
    bool first = true;
    for (const auto &i : c) {
        if (first) {
            first = false;
        } else {
            ss << d;
        }
        ss << i;
    }
    return ss.str();
}

template<typename First, typename Second>
std::ostream &operator<<(std::ostream &out, const std::pair<First, Second> &p)
{
    return out << '(' << p.first << ',' << p.second << ')';
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vi)
{
    return out << '[' << Join(vi, ',') << ']';
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &s)
{
    return out << '{' << Join(s, ',') << '}';
}

template<typename Key, typename Value>
std::ostream &operator<<(std::ostream &out, const std::map<Key, Value> &m)
{
    return out << '{' << Join(m, ',') << '}';
}

template<class T, class U>
void AssertEqual(const T &t, const U &u, const std::string &hint = {})
{
    if (t != u) {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

inline void Assert(bool b, const std::string &hint = {})
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
    void RunTest(TestFunc func, const std::string &test_name)
    {
        try {
            func();
            std::cerr << test_name << " OK" << std::endl;
        } catch (std::runtime_error &e) {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0) {
            std::cerr << fail_count << " unit tests failed. Terminate"
                      << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c)
{
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    if (qFuzzyIsNull(a)) {
        if (qFuzzyIsNull(b)) {
            return 0;
        }
        return 1;
    }
    auto d = b * b - 4 * a * c;
    if (qFuzzyIsNull(d)) {
        return 1;
    }
    if (d > 0) {
        return 2;
    }
    return 0;
}

void TestZeroRoot()
{
    AssertEqual(GetDistinctRealRootCount(0.F, 0.F, 2.F), 0);
    AssertEqual(GetDistinctRealRootCount(2.F, 6.F, 9.F), 0);
}

void TestOneRoot()
{
    AssertEqual(GetDistinctRealRootCount(0.F, 2.F, 2.F), 1);
    AssertEqual(GetDistinctRealRootCount(1.F, 6.F, 9.F), 1);
}

void TestTwoRoots()
{
    AssertEqual(GetDistinctRealRootCount(1.F, 6.F, 8.F), 2);
}
void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestZeroRoot, "TestZeroRoot");
    tr.RunTest(TestOneRoot, "TestOneRoot");
    tr.RunTest(TestTwoRoots, "TestTwoRoots");
}

int main()
{
    TestAll();
    return 0;
}
