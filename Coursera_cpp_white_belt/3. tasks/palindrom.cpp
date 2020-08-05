#include <string>
bool IsPalindrom(std::string s) {
    std::string reverse;
    for (int i = s.size() - 1; i >= 0; i--) {
        reverse += s[i];
    }
    return !(s != reverse);
}