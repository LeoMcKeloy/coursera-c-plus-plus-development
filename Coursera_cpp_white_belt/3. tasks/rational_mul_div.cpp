#include <iostream>
using namespace std;

class Rational {
public:
    Rational() {
        num = 0;
        den = 1;
    }

    Rational(int numerator, int denominator) {
        if (denominator < 0) {
            denominator *= -1;
            numerator *= -1;
        }
        if (numerator == 0) {
            denominator = 1;
        }
        int gcd = GCD(numerator, denominator);
        num = numerator / gcd;
        den = denominator / gcd;
    }

    int Numerator() const {
        return num;
    }

    int Denominator() const {
        return den;
    }

private:
    int num;
    int den;

    int GCD(int n1, int n2) {
        int div;
        if (n1 == n2)
            return n1;
        int d = n1 - n2;
        if (d < 0)
            d = -d;
        div = GCD(n2, d);
        return div;
    }
};

bool operator==(const Rational& left, const Rational& right) {
    if (left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator())
        return true;
    return false;
}

const Rational operator*(const Rational& left, const Rational& right) {
    return Rational(left.Numerator() * right.Numerator(),
                    left.Denominator() * right.Denominator());
}

const Rational operator/(const Rational& left, const Rational& right) {
    return Rational(left.Numerator() * right.Denominator(),
                    left.Denominator() * right.Numerator());
}

int main() {
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
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}