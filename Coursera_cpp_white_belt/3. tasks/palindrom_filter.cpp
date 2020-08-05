#include <vector>
#include <string>
using namespace std;

bool IsPalindrom(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
    vector<string> palindroms;
    for (auto w : words) {
        if (IsPalindrom(w) && w.size() >= minLength)
            palindroms.push_back(w);
    }
    return palindroms;
}