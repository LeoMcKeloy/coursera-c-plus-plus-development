#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    string command, country, new_country_name, capital;
    map<string, string> countries;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> command;
        if ( command == "DUMP") {
            if (countries.size() == 0) {
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (const auto& item : countries) {
                    cout << item.first << '/' << item.second << ' ';
                }
            }
        }
        else if (command == "ABOUT") {
            cin >> country;
            const auto found = countries.find(country);
            if (found == countries.cend())
                cout << "Country " << country << " doesn't exist" << endl;
            else
                cout <<"Country " << country << " has capital " << countries[country] << endl;
        }
        else if (command == "RENAME") {
            cin >> country >> new_country_name;
            if (country == new_country_name) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                const auto found = countries.find(country);
                if (found == countries.cend())
                    cout << "Incorrect rename, skip" << endl;
                else {
                    const auto found = countries.find(new_country_name);
                    if (found == countries.cend()) {
                        string tmp = countries[country];
                        countries.erase(country);
                        countries[new_country_name] = tmp;
                        cout << "Country " << country << " with capital " << countries[new_country_name]
                        << " has been renamed to " << new_country_name << endl;
                    } else {
                        cout << "Incorrect rename, skip" << endl;
                    }
                }
            }
        }
        else if (command == "CHANGE_CAPITAL") {
            cin >> country >> capital;
            const auto found = countries.find(country);
            if (found == countries.cend()) {
                cout << "Introduce new country " << country << " with capital " << capital << endl;
                countries[country]  = capital;
            } else {
                if (countries[country]  == capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from "
                    << countries[country] << " to " << capital << endl;
                    countries[country]  = capital;
                }
            }
        }
    }
    return 0;
}