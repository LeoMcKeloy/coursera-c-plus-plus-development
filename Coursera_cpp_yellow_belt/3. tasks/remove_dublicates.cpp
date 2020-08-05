#include <iostream>
#include <vector>
#include <set>

using namespace std;
template <typename T>
void RemoveDuplicates(vector<T>& elements) {
    set<T> s;
    for (auto it = elements.begin(); it != elements.end(); it++) {
        s.insert(*it);
    }
    elements.clear();
    for (auto item : s) {
        elements.push_back(item);
    }
}

int main() {
    vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        cout << x << " ";
    }
    cout << endl;

    vector<string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const string& s : v2) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}

/*
#include <algorithm>
using namespace std;

template <typename DataType>
void RemoveDuplicates(vector<DataType>& elements) {
  sort(begin(elements), end(elements));
  elements.erase(
      unique(begin(elements), end(elements)),
      elements.end());
}
*/