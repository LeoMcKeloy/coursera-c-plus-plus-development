#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string ToLower(string& s) {
    for (auto& c : s)
        c = tolower(c);
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& x : v) {
        cin >> x;
    }

    sort(begin(v), end(v),
         [](string l, string r) {
             return ToLower(l) < ToLower(r);
         }
    );

    for (auto x : v) {
        cout << x << " ";
    }

    return 0;
}

