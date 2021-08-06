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

int main()
{
    {
        const Rational r(3, 10);
        if (r.Numerator() != 3 || r.Denominator() != 10) {
            cout << "Rational(3, 10) != 3/10" << endl;
            return 1;
        }
    }

    {
        const Rational r(8, 12);
        if (r.Numerator() != 2 || r.Denominator() != 3) {
            cout << "Rational(8, 12) != 2/3" << endl;
            return 2;
        }
    }

    {
        const Rational r(-4, 6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(-4, 6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(4, -6);
        if (r.Numerator() != -2 || r.Denominator() != 3) {
            cout << "Rational(4, -6) != -2/3" << endl;
            return 3;
        }
    }

    {
        const Rational r(0, 15);
        if (r.Numerator() != 0 || r.Denominator() != 1) {
            cout << "Rational(0, 15) != 0/1" << endl;
            return 4;
        }
    }

    {
        const Rational defaultConstructed;
        if (defaultConstructed.Numerator() != 0
                || defaultConstructed.Denominator() != 1) {
            cout << "Rational() != 0/1" << endl;
            return 5;
        }
    }

    cout << "OK" << endl;
    return 0;
}
