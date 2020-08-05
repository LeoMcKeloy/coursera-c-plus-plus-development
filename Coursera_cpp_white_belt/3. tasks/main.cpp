#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    if (a == 0) {
        if (b != 0) {
            x1 = -c / b;
            cout << x1 << endl;
        }
    }
    else {
        if (b == 0) {
            d = -c / a;
            if (d > 0) {
                x1 = sqrt(d);
                x2 = -1 * sqrt(d);
                cout <<  x1 << ' ' << x2 << endl;
            }
        }
        else {
            d = b * b - 4 * a * c;
            if (d > 0) {
                x1 = (-b - sqrt(d)) / (2 * a);
                x2 = (-b + sqrt(d)) / (2 * a);
                cout << x1 << ' ' << x2 << endl;
            }
            else if (d == 0) {
                x1 = -b / (2 * a);
                cout << x1 << endl;
            }
        }
    }
    return 0;
}
