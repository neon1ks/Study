#include <cassert>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <vector>

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
    {
        const set<Rational> rs = { { 1, 2 }, { 1, 25 }, { 3, 4 }, { 3, 4 },
            { 1, 2 } };
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{ { 1, 25 }, { 1, 2 }, { 3, 4 } }) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{ 1, 2 }];
        ++count[{ 1, 2 }];

        ++count[{ 2, 3 }];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}

/*
#include <iostream>

using namespace std;

// один из способов вычисления наибольшего общего делителя (НОД) — рекурсивный:
// вместо цикла функция будет вызывать себя же, но с другими аргументами
int GreatestCommonDivisor(int a, int b) {
  if (b == 0) {
    return a;
  } else {
    return GreatestCommonDivisor(b, a % b);
  }
}

class Rational {
public:
  Rational() {  // дробь по умолчанию — 0/1
    numerator = 0;
    denominator = 1;
  }
  Rational(int new_numerator, int new_denominator) {
    const int gcd = GreatestCommonDivisor(new_numerator, new_denominator);
    // сократим дробь, разделив числитель и знаменатель на их НОД
    numerator = new_numerator / gcd;
    denominator = new_denominator / gcd;
    // знаменатель должен быть положительным
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

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() &&
      lhs.Denominator() == rhs.Denominator();
}

// используем обычную формулу сложения дробей, основанную на приведении слагаемых к общему знаменателю
Rational operator + (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// вычитание реализуем аналогично сложению
// дублирования кода можно было избежать, определив для класса Rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
Rational operator - (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
  return {
      lhs.Numerator() * rhs.Numerator(),
      lhs.Denominator() * rhs.Denominator()
  };
}

// деление равносильно умножению на обратную («перевёрнутую») дробь
Rational operator / (const Rational& lhs, const Rational& rhs) {
  return lhs * Rational(rhs.Denominator(), rhs.Numerator());
}

istream& operator >> (istream& is, Rational& r) {
  int n, d;
  char c;

  if (is) {
      is >> n >> c >> d;
      if (is) {
          if (c == '/') {
              r = Rational(n, d);
          }
          else {
              is.setstate(ios_base::failbit);
          }
      }
  }

  return is;
}

ostream& operator << (ostream& os, const Rational& r) {
  return os << r.Numerator() << '/' << r.Denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулём, что равносильно сравнению с нулём числителя
bool operator < (const Rational& lhs, const Rational& rhs) {
  return (lhs - rhs).Numerator() < 0;
}

*/
