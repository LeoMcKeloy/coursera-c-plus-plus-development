#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ReversibleString {
public:
    ReversibleString() {
    }
    ReversibleString(const string& str) {
        s = str;
    }
    void Reverse() {
        reverse(begin(s), end(s));
    }
    string ToString() const {
        return s;
    }
private:
    string s;
};