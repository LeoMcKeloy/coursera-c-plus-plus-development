#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (a % b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    cout << b << endl;
    return b;
}
