#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

string BuildCharCounters(string word, string anagram) {
    map<char, int> m1;
    map<char, int> m2;
    for (const auto& c : word) {
        m1[c]++;
    }
    for (const auto& c : anagram) {
        m2[c]++;
    }
    if (m1 == m2)
        return "YES";
    return "NO";
}

int main() {
    vector<string> v;
    string word, anagram;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> word >> anagram;
        string s = BuildCharCounters(word, anagram);
        v.push_back(s);
    }
    for (const auto& s: v)
        cout << s << endl;
    return 0;
}

