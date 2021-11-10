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

#ifdef ONLY_HOME
class Person
{
public:
    void ChangeFirstName(int year, const string &first_name)
    {
        history[year].FirstName = first_name;
    }
    void ChangeLastName(int year, const string &last_name)
    {
        history[year].LastName = last_name;
    }
    string GetFullName(int year)
    {
        string first_name;
        string last_name;

        for (const auto &y : history) {
            if (year < y.first) {
                break;
            }
            if (!y.second.FirstName.empty()) {
                first_name = y.second.FirstName;
            }
            if (!y.second.LastName.empty()) {
                last_name = y.second.LastName;
            }
            if (year == y.first) {
                break;
            }
        }

        if (first_name.empty() && last_name.empty()) {
            return "Incognito";
        }
        if (first_name.empty()) {
            return last_name + " with unknown first name";
        }
        if (last_name.empty()) {
            return first_name + " with unknown last name";
        }
        return first_name + ' ' + last_name;
    }

private:
    struct FirstAndLastName
    {
        string FirstName;
        string LastName;
    };
    map<int, FirstAndLastName> history;
    // приватные поля
};
#endif

void TestIncognito()
{
    Person p;
    AssertEqual(p.GetFullName(2000), string("Incognito"));
    string first_name = "name";
    string last_name = "last_name";
    p.ChangeFirstName(2001, first_name);
    p.ChangeLastName(2001, last_name);
    AssertEqual(p.GetFullName(2000), string("Incognito"));
}

void TestUnknownFirstName()
{
    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2001, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = last_name + " with unknown first name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2001, first_name);
        p.ChangeLastName(1998, "other last name");
        p.ChangeLastName(2000, last_name);
        string expected = last_name + " with unknown first name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2001, first_name);
        p.ChangeLastName(2000, last_name);
        p.ChangeLastName(1998, "other last name");
        string expected = last_name + " with unknown first name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2001, first_name);
        p.ChangeLastName(1999, last_name);
        string expected = last_name + " with unknown first name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2001, first_name);
        p.ChangeLastName(1998, "other last name");
        p.ChangeLastName(1999, last_name);
        string expected = last_name + " with unknown first name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2001, first_name);
        p.ChangeLastName(1999, last_name);
        p.ChangeLastName(1998, "other last name");
        string expected = last_name + " with unknown first name";
        AssertEqual(p.GetFullName(2000), expected);
    }
}

void TestUnknownLastName()
{
    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2001, last_name);
        string expected = first_name + " with unknown last name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1998, "other first name");
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2001, last_name);
        string expected = first_name + " with unknown last name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeFirstName(1998, "other first name");
        p.ChangeLastName(2001, last_name);
        string expected = first_name + " with unknown last name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(2001, last_name);
        string expected = first_name + " with unknown last name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1998, "other first name");
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(2001, last_name);
        string expected = first_name + " with unknown last name";
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1999, first_name);
        p.ChangeFirstName(1998, "other first name");
        p.ChangeLastName(2001, last_name);
        string expected = first_name + " with unknown last name";
        AssertEqual(p.GetFullName(2000), expected);
    }
}

void TestNow()
{
    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(1999, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1998, "other first name");
        p.ChangeLastName(1998, "other last name");
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1998, "other first name");
        p.ChangeLastName(1998, "other last name");
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(1999, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        p.ChangeFirstName(1998, "other first name");
        p.ChangeLastName(1998, "other last name");
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }

    {
        Person p;
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(1999, last_name);
        p.ChangeFirstName(1998, "other first name");
        p.ChangeLastName(1998, "other last name");
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
}

void TestNowAndBefore()
{
    {
        Person p;
        p.ChangeFirstName(1999, "first name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeLastName(1999, "first last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeFirstName(1999, "first name");
        p.ChangeLastName(1999, "first last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
}

void TestNowAndAfter()
{
    {
        Person p;
        p.ChangeFirstName(2001, "change name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeLastName(2001, "change last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeFirstName(2001, "change name");
        p.ChangeLastName(2001, "change last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
}

void TestNowAndBeforeAndAfter() {
    {
        Person p;
        p.ChangeFirstName(2001, "change name");
        p.ChangeLastName(2001, "change last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        p.ChangeFirstName(1998, "first name");
        p.ChangeLastName(1998, "first last name");
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeFirstName(1998, "first name");
        p.ChangeLastName(1998, "first last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(2000, first_name);
        p.ChangeLastName(2000, last_name);
        p.ChangeFirstName(2001, "change name");
        p.ChangeLastName(2001, "change last name");
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeFirstName(2001, "change name");
        p.ChangeLastName(2001, "change last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(1999, last_name);
        p.ChangeFirstName(1998, "first name");
        p.ChangeLastName(1998, "first last name");
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }
    {
        Person p;
        p.ChangeFirstName(1998, "first name");
        p.ChangeLastName(1998, "first last name");
        string first_name = "name";
        string last_name = "last_name";
        p.ChangeFirstName(1999, first_name);
        p.ChangeLastName(1999, last_name);
        p.ChangeFirstName(2001, "change name");
        p.ChangeLastName(2001, "change last name");
        string expected = first_name + ' ' + last_name;
        AssertEqual(p.GetFullName(2000), expected);
    }

}

void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestIncognito, "TestIncognito");
    tr.RunTest(TestUnknownFirstName, "TestUnknownFirstName");
    tr.RunTest(TestUnknownLastName, "TestUnknownLastName");
    tr.RunTest(TestNowAndBefore, "TestNowAndBefore");
    tr.RunTest(TestNowAndAfter, "TestNowAndAfter");
    tr.RunTest(TestNowAndBeforeAndAfter, "TestNowAndBeforeAndAfter");
}

int main()
{
    TestAll();
    return 0;
}
