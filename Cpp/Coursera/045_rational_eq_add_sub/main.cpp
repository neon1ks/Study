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

    int Numerator() const
    {
        // Реализуйте этот метод
        return m_numerator;
    }

    int Denominator() const
    {
        // Реализуйте этот метод
        return m_denominator;
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

    if (numerator != 0 && denominator != 0) {
        int d = std::gcd(abs(numerator), abs(denominator));
        if (d > 1) {
            numerator /= d;
            denominator /= d;
        }
    }

    return { numerator, denominator };
}

Rational operator-(const Rational &l, const Rational &r)
{
    if (l.Denominator() == 0 || r.Denominator() == 0) {
        return { 0, 1 };
    }

    int denominator = lcm(l.Denominator(), r.Denominator());
    int numerator = l.Numerator() * (denominator / l.Denominator())
                    - r.Numerator() * (denominator / r.Denominator());

    if (numerator != 0 && denominator != 0) {
        int d = std::gcd(abs(numerator), abs(denominator));
        if (d > 1) {
            numerator /= d;
            denominator /= d;
        }
    }

    return { numerator, denominator };
}

int main()
{
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
