#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main() {
    map<set<string>, int> bus_stops;
    string stop;
    int q, n;
    cin >> q;
    for (int i = 0; i < q; i++) {
        set<string> stops;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> stop;
            stops.insert(stop);
        }
        if (bus_stops.count(stops) == 0) {
            const int new_value = bus_stops.size() + 1;
            bus_stops[stops] = new_value;
            cout << "New bus " << new_value << endl;

        } else {
            cout << "Already exists for " << bus_stops[stops] << endl;
        }
    }
    return 0;
}

