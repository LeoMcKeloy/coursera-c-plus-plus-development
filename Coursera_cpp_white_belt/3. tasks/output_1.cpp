#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    ifstream input("input.txt");
    double d;
    cout << fixed << setprecision(3);
    if (input.is_open()) {
        while (input >> d) {
            cout << d << endl;
        }
    }
    return 0;
}