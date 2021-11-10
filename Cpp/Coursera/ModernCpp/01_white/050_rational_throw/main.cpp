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
            throw invalid_argument("denominator is zero");
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
        throw domain_error("the right argument is zero");
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
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument &) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error &) {
    }

    cout << "OK" << endl;
    return 0;
}

/*
#include <iostream>
#include <exception>

using namespace std;

int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      // бросаем исключение в случае нулевого знаменателя
      throw invalid_argument("");
    }
    const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;
    if (denominator < 0) {
      denominator = -denominator;
      numerator = -numerator;
    }
  }

  int Numerator() const {
    return numerator;
  }

  int Denominator() const {
    return denominator;
  }

private:
  int numerator;
  int denominator;
};

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
  // проверяем делитель на 0 (что равносильно проверке на 0 его числителя)
  if (rhs.Numerator() == 0) {
    throw domain_error("");
  }
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}
*/
