#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> words;

    auto range_begin = begin(s);
    auto range_end = end(s);

    while (true) {
        auto it = find(range_begin, range_end, ' ');
        words.push_back(string(range_begin, it));

        if (it == range_end) {
            break;
        } else {
            range_begin = it + 1;
        }

    }

    return words;
}

int main() {
    string s = "C Cpp Java Python";

    vector<string> words = SplitIntoWords(s);
    cout << words.size() << " ";
    for (auto it = begin(words); it != end(words); ++it) {
        if (it != begin(words)) {
            cout << "/";
        }
        cout << *it;
    }
    cout << endl;

    return 0;
}