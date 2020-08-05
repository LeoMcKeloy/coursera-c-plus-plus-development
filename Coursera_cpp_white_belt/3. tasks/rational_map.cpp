#include <iostream>
#include <map>
#include <set>
#include <vector>
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

bool operator>(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) > double(b.Numerator() / (double)b.Denominator());
}
bool operator<(Rational a, Rational b) {
    return (a.Numerator() / (double)a.Denominator()) < (b.Numerator() / (double)b.Denominator());
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }
    cout << "OK" << endl;
    return 0;
}