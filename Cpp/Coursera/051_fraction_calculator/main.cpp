#include <cassert>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <vector>

#include <exception>
#include <stdexcept>

using namespace std;

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
        if (denominator == 0) {
            throw invalid_argument("Invalid argument");
        }

        if (numerator == 0) {
            m_numerator = 0;
            m_denominator = 1;
        } else if (denominator < 0) {
            m_numerator = -numerator;
            m_denominator = -denominator;
        } else {
            m_numerator = numerator;
            m_denominator = denominator;
        }

        Simplify();
    }

    int Numerator() const { return m_numerator; }
    int Denominator() const { return m_denominator; }

    void Simplify()
    {
        if (m_numerator != 0 && m_denominator != 0) {
            int d = std::gcd(abs(m_numerator), abs(m_denominator));
            if (d > 1) {
                m_numerator /= d;
                m_denominator /= d;
            }
        }
    }

private:
    int m_numerator;
    int m_denominator;
};

bool operator==(const Rational &l, const Rational &r)
{
    return (l.Numerator() == r.Numerator()
            && l.Denominator() == r.Denominator());
}

Rational operator+(const Rational &l, const Rational &r)
{
    assert(l.Denominator() != 0);
    assert(r.Denominator() != 0);

    int denominator = lcm(l.Denominator(), r.Denominator());
    int numerator = l.Numerator() * (denominator / l.Denominator())
                    + r.Numerator() * (denominator / r.Denominator());

    return { numerator, denominator };
}

Rational operator-(const Rational &l, const Rational &r)
{
    assert(l.Denominator() != 0);
    assert(r.Denominator() != 0);

    int denominator = lcm(l.Denominator(), r.Denominator());
    int numerator = l.Numerator() * (denominator / l.Denominator())
                    - r.Numerator() * (denominator / r.Denominator());

    return { numerator, denominator };
}

Rational operator*(const Rational &l, const Rational &r)
{
    return { l.Numerator() * r.Numerator(), l.Denominator() * r.Denominator() };
}

Rational operator/(const Rational &l, const Rational &r)
{
    if (r.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return { l.Numerator() * r.Denominator(), l.Denominator() * r.Numerator() };
}

ostream &operator<<(ostream &stream, const Rational &value)
{
    stream << value.Numerator() << '/' << value.Denominator();
    return stream;
}

istream &operator>>(istream &stream, Rational &value)
{
    int numerator = 0;
    int denominator = 0;
    char c = 0;

    if (stream) {
        stream >> numerator;
    } else {
        return stream;
    }
    if (stream) {
        stream >> c;
    } else {
        return stream;
    }
    if (stream) {
        stream >> denominator;
    } else {
        return stream;
    }
    if (c != '/') {
        return stream;
    }
    value = { numerator, denominator };

    return stream;
}

bool operator<(const Rational &lhs, const Rational &rhs)
{
    assert(lhs.Denominator() != 0);
    assert(rhs.Denominator() != 0);

    int denominator = lcm(lhs.Denominator(), rhs.Denominator());
    return lhs.Numerator() * (denominator / lhs.Denominator())
           < rhs.Numerator() * (denominator / rhs.Denominator());
}

int main()
{
    try {
        Rational first;
        Rational second;
        char oper = '\0';
        cin >> first >> oper >> second;
        Rational result;
        if (oper == '+') {
            result = first + second;
        } else if (oper == '-') {
            result = first - second;
        } else if (oper == '*') {
            result = first * second;
        } else if (oper == '/') {
            result = first / second;
        }
        cout << result << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    } catch (const domain_error &e) {
        cout << e.what() << endl;
    } catch (const exception &e) {
        ;
    }
    return 0;
}
