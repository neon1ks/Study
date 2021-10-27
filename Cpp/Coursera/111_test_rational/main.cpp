#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <numeric>

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

#ifdef ONLY_HOME
class Rational
{
public:
    Rational()
    {
        // Реализуйте конструктор по умолчанию
        m_numerator = 0;
        m_denominator = 1;
    }

    Rational(int numerator, int denominator)
    {
        // Реализуйте конструктор
        if (numerator != 0 && denominator != 0) {
            int d = std::gcd(abs(numerator), abs(denominator));
            if (d > 1) {
                numerator /= d;
                denominator /= d;
            }
        }

        if (numerator == 0 || denominator == 0) {
            m_numerator = 0;
            m_denominator = 1;
        } else if (denominator < 0) {
            m_numerator = -numerator;
            m_denominator = -denominator;
        } else {
            m_numerator = numerator;
            m_denominator = denominator;
        }
    }

    [[nodiscard]] int Numerator() const
    {
        // Реализуйте этот метод
        return m_numerator;
    }

    [[nodiscard]] int Denominator() const
    {
        // Реализуйте этот метод
        return m_denominator;
    }

private:
    int m_numerator;
    int m_denominator;
};
#endif

void TestDefault()
{
    Rational r;
    AssertEqual(r.Numerator(), 0);
    AssertEqual(r.Denominator(), 1);
}

void TestNormal()
{
    {
        Rational r(1, 2);
        AssertEqual(r.Numerator(), 1);
        AssertEqual(r.Denominator(), 2);
    }
    {
        Rational r(-1, -2);
        AssertEqual(r.Numerator(), 1);
        AssertEqual(r.Denominator(), 2);
    }
    {
        Rational r(2, 4);
        AssertEqual(r.Numerator(), 1);
        AssertEqual(r.Denominator(), 2);
    }
}

void TestNegativeNumber()
{
    {
        Rational r(-1, 2);
        AssertEqual(r.Numerator(), -1);
        AssertEqual(r.Denominator(), 2);
    }
    {
        Rational r(1, -2);
        AssertEqual(r.Numerator(), -1);
        AssertEqual(r.Denominator(), 2);
    }
    {
        Rational r(-2, 4);
        AssertEqual(r.Numerator(), -1);
        AssertEqual(r.Denominator(), 2);
    }
    {
        Rational r(2, -4);
        AssertEqual(r.Numerator(), -1);
        AssertEqual(r.Denominator(), 2);
    }
}

void TestZero()
{
    {
        Rational r(0, 1);
        AssertEqual(r.Numerator(), 0);
        AssertEqual(r.Denominator(), 1);
    }
    {
        Rational r(0, -1);
        AssertEqual(r.Numerator(), 0);
        AssertEqual(r.Denominator(), 1);
    }
    {
        Rational r(0, 10);
        AssertEqual(r.Numerator(), 0);
        AssertEqual(r.Denominator(), 1);
    }
    {
        Rational r(0, -10);
        AssertEqual(r.Numerator(), 0);
        AssertEqual(r.Denominator(), 1);
    }
}

void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestDefault, "TestDefault");
    tr.RunTest(TestNormal, "TestNormal");
    tr.RunTest(TestNegativeNumber, "TestNegativeNumber");
    tr.RunTest(TestZero, "TestZero");
}

int main()
{
    TestAll();
    return 0;
}
