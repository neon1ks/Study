#include <iostream>
#include <sstream>
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

int main()
{
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2
                 << endl;
            return 4;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1
                 << " " << r2 << endl;
            return 5;
        }
    }

    {
        istringstream input1("1*2"), input2("1/"), input3("/4");
        Rational r1, r2, r3;
        input1 >> r1;
        input2 >> r2;
        input3 >> r3;
        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
        if (!correct) {
            cout << "Reading of incorrectly formatted rationals shouldn't "
                    "change arguments: "
                 << r1 << " " << r2 << " " << r3 << endl;

            return 6;
        }
    }

    cout << "OK" << endl;
    return 0;
}
