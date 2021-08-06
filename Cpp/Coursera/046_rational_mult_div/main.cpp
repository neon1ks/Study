#include <iostream>
#include <numeric>
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
// Реализуйте для класса Rational операторы ==, + и -

bool operator==(const Rational &l, const Rational &r)
{
    return (l.Numerator() == r.Numerator()
            && l.Denominator() == r.Denominator());
}

Rational operator+(const Rational &l, const Rational &r)
{
    if (l.Denominator() == 0 || r.Denominator() == 0) {
        return { 0, 1 };
    }

    int denominator = lcm(l.Denominator(), r.Denominator());
    int numerator = l.Numerator() * (denominator / l.Denominator())
                    + r.Numerator() * (denominator / r.Denominator());

    Rational result = { numerator, denominator };
    result.Simplify();
    return result;
}

Rational operator-(const Rational &l, const Rational &r)
{
    if (l.Denominator() == 0 || r.Denominator() == 0) {
        return { 0, 1 };
    }

    int denominator = lcm(l.Denominator(), r.Denominator());
    int numerator = l.Numerator() * (denominator / l.Denominator())
                    - r.Numerator() * (denominator / r.Denominator());

    Rational result = { numerator, denominator };
    result.Simplify();
    return result;
}

Rational operator*(const Rational &l, const Rational &r)
{
    if (l.Denominator() == 0 || r.Denominator() == 0) {
        return { 0, 1 };
    }

    Rational result = { l.Numerator() * r.Numerator(),
        l.Denominator() * r.Denominator() };
    result.Simplify();
    return result;
}

Rational operator/(const Rational &l, const Rational &r)
{
    if (l.Denominator() == 0 || r.Denominator() == 0 || l.Numerator() == 0
            || r.Numerator() == 0) {
        return { 0, 1 };
    }

    Rational result = { l.Numerator() * r.Denominator(),
        l.Denominator() * r.Numerator() };
    result.Simplify();
    return result;
}

int main()
{
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << c.Numerator() << '/' << c.Denominator() << endl;
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
