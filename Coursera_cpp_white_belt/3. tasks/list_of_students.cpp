#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    string surname;
    int birth_day;
    int birth_month;
    int birth_year;
};

int main() {
    vector<Student> students;
    string name, surname, request;
    int n, m, day, month, year, s_num;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name >> surname >> day >> month >> year;
        Student s;
        s.name = name;
        s.surname = surname;
        s.birth_day = day;
        s.birth_month = month;
        s.birth_year = year;
        students.push_back(s);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> request >> s_num;
        if (request == "name" && s_num > 0 && s_num <= n) {
            cout << students[s_num - 1].name << ' ' << students[s_num - 1].surname << endl;
        }
        else if (request == "date" && s_num > 0 && s_num <= n) {
            cout << students[s_num - 1].birth_day << '.' << students[s_num - 1].birth_month << '.' <<
            students[s_num - 1].birth_year << endl;
        } else {
            cout << "bad request" << endl;
        }
    }
    return 0;
}