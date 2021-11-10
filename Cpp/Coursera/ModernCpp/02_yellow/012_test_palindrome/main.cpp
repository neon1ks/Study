#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <numeric>
#include <random>

using namespace std;

[[nodiscard]] constexpr bool qFuzzyCompare(double p1, double p2)
{
    return (std::abs(p1 - p2) * 1000000000000. <= std::min(std::abs(p1), std::abs(p2)));
}

[[nodiscard]] constexpr bool qFuzzyCompare(float p1, float p2)
{
    return (std::abs(p1 - p2) * 100000.F <= std::min(std::abs(p1), std::abs(p2)));
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
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

#ifdef ONLY_HOME
bool IsPalindrom(const string &text)
{
    if (text.empty()) {
        return true;
    }
    size_t i_begin = 0;
    size_t i_end = text.size() - 1;
    while (i_begin < i_end) {
        if (text[i_begin] != text[i_end]) {
            return false;
        }
        ++i_begin;
        --i_end;
    }

    return true;
}
#endif

void TestDefault()
{
    string text = {};
    Assert(IsPalindrom(text));
}

void TestOne()
{
    string text = {"a"};
    Assert(IsPalindrom(text));
}

void TestWithSpace()
{
    {
        string text = {"a a"};
        AssertEqual(IsPalindrom(text), true, "Word = \"" + text + "\"");
    }
    {
        string text = {" a a "};
        AssertEqual(IsPalindrom(text), true, "Word = \"" + text + "\"");
    }
    {
        string text = {" a a"};
        AssertEqual(IsPalindrom(text), false, "Word = \"" + text + "\"");
    }
    {
        string text = {"a a "};
        AssertEqual(IsPalindrom(text), false, "Word = \"" + text + "\"");
    }
}

void testMissOneChar()
{
    const size_t N = 100;
    for (size_t i = 2; i <= N; ++i) {
        string word(i, 'a');
        for (size_t j = 0; j < i; ++j) {
            if (j == i / 2 && i % 2 == 1) {
                continue;
            }
            word[j] = 'b';
            string hint = "Word = \"" + word + "\"";
            AssertEqual(IsPalindrom(word), false, hint);
            word[j] = 'a';
        }
    }
}

void testCorrect()
{
    const size_t N = 100;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<char> char_dist(32, 126);
    std::uniform_int_distribution<size_t> len_dist(1, N);

    for (size_t i = 0; i < N; ++i) {
        string word(len_dist(gen) * 2, '\0');

        for (size_t j = 0; j < word.size() / 2; ++j) {
            word[j] = word[word.size() - 1 - j] = char_dist(gen);
        }
        string hint = "Word = \"" + word + "\"";
        AssertEqual(IsPalindrom(word), true, hint);
    }

    for (size_t i = 0; i < N; ++i) {
        string word(len_dist(gen) * 2 + 1, '\0');

        for (size_t j = 0; j < word.size() / 2; ++j) {
            word[j] = word[word.size() - 1 - j] = char_dist(gen);
        }
        word[word.size() / 2] = char_dist(gen);
        string hint = "Word = \"" + word + "\"";
        AssertEqual(IsPalindrom(word), true, hint);
    }
}



void TestAll()
{
    TestRunner tr;
    tr.RunTest(TestDefault, "TestDefault");
    tr.RunTest(TestOne, "TestOne");
    tr.RunTest(TestWithSpace, "TestWithSpace");
    tr.RunTest(testMissOneChar, "testMissOneChar");
    tr.RunTest(testCorrect, "testCorrect");
}

int main()
{
    TestAll();
    return 0;
}
