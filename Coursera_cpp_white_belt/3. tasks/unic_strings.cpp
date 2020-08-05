#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    string s;
    set<string> strings;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        strings.insert(s);
    }
    cout << strings.size();
    return 0;
}

