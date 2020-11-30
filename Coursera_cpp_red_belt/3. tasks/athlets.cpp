#include <iostream>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

istream& operator>> (istream& is, pair<int, int>& p) {
    is >> p.first >> p.second;
    return is;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX_ATHLETES = 100000;
    list<int> list_athletes;
    vector<list<int>::iterator> athlete_pos
        (MAX_ATHLETES + 1, list_athletes.end());

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++) {
        pair<int, int> sportsmen;
        cin >> sportsmen;
        athlete_pos[sportsmen.first] = list_athletes.insert
                (athlete_pos[sportsmen.second], sportsmen.first);
    }
    for (int i : list_athletes) {
        cout << i << ' ' << '\n';
    }
    return 0;
}