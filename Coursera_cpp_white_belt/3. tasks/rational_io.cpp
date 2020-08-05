#include <iostream>
#include <sstream>
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

istream& operator >> (istream& stream, Rational& r) {
    int p, q;
    if (stream >> p && stream.ignore(1) && stream >> q) {
        r = {p, q};
    }
    return stream;
}

ostream& operator << (ostream& stream, const Rational& r) {
    stream << r.Numerator() << "/" << r.Denominator();
    return stream;
}

int main() {
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
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }
    cout << "OK" << endl;
    return 0;
}

