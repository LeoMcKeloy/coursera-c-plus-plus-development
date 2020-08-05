#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int flag = 0;
    cin >> s;
    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == 'f') {
            flag++;
            if (flag == 2) {
                cout << i << endl;
            }
        }
    }
    if (flag == 1)
        cout << -1 << endl;
    else if (flag == 0)
        cout << -2 << endl;
    return 0;
}

