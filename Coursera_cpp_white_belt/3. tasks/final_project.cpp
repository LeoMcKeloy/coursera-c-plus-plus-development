#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

class Date {
public:
    Date() {
        year = 0;
        month = 0;
        day = 0;
    };

    Date(const int& new_year, const int& new_month, const int& new_day) {
        year = new_year;
        if (new_month < 1 || new_month > 12) {
            string error;
            error = "Month value is invalid: " + to_string(new_month);
            throw runtime_error(error);
        }
        else if (new_day < 1 || new_day > 31) {
            string error;
            error = "Day value is invalid: " + to_string(new_day);
            throw runtime_error(error);
        } else {
            month = new_month;
            day = new_day;
        }
    };

    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
    
private:
    int year;
    int month;
    int day;
};

void NextSymbol(stringstream& d, const string& data_str) {
    if (d.peek() != '-') {
        stringstream ss;
        ss << "Wrong date format: " + data_str;
        throw runtime_error(ss.str());
    }
    d.ignore(1);
}

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth()) {
        return lhs.GetDay() < rhs.GetDay();
    }
    else if (lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetYear() < rhs.GetYear();
    }
}

ostream& operator << (ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() << '-'
           << setw(2) << setfill('0') << date.GetMonth() << '-'
           << setw(2) << setfill('0') << date.GetDay();
    return stream;
}

istream& operator >> (istream& stream, Date& date) {
    int year = 10000;
    int month = 10000;
    int day = 10000;

    string data_str;
    string endError = "";
    if (stream >> data_str) {
        stringstream d(data_str);
        d >> year;
        NextSymbol(d, data_str);
        d >> month;
        NextSymbol(d, data_str);
        d >> day;
        d >> endError;
        if (year > -1 && year < 10000 && month < 10000 && day < 10000 && endError == "") {
            date = Date(year, month, day);
            return stream;
        }
        else {
            stringstream string_error;
            string_error << "Wrong date format: " + data_str;
            throw runtime_error(string_error.str());
        }
    }
    else {
        stringstream string_error;
        string_error << "Wrong date format: " + data_str;
        throw runtime_error(string_error.str());
    }

}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        database[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (database.count(date)) {
            if (database[date].count(event)) {
                database[date].erase(event);
                return true;
            }
        }
        return false;
    }
    int  DeleteDate(const Date& date) {
        if (database.count(date)) {
            int s = database[date].size();
            database.erase(date);
            return s;
        }
        return 0;
    }

    void Find(const Date& date) const {
        if (database.count(date)) {
            for (auto& item : database.at(date)) {
                cout << item << endl;
            }
        }
    }

    void Print() const {
        for (auto& f : database) {
            for (auto& s : f.second) {
                cout << f.first << ' ' << s << endl;
            }
        }
    }

private:
    map<Date, set<string>> database;
};

int main() {
    Database DB;

    string command;
    try {
        while (getline(cin, command)) {
            stringstream stream(command);
            string com = "";
            Date date;
            string event = "";
            if (stream >> com) {
                if (com == "Add") {
                    if (stream >> date) {
                        if (stream >> event) {
                            DB.AddEvent(date, event);
                        } else {
                            stringstream ss;
                            ss << "Wrong date format: " << date;
                            throw runtime_error(ss.str());
                        }
                    }
                }
                else if (com == "Find") {
                    if (stream >> date) {
                        DB.Find(date);
                    }
                }
                else if (com == "Print") {
                    DB.Print();
                }
                else if (com == "Del") {
                    if (stream >> date) {
                        if (stream >> event) {
                            if (DB.DeleteEvent(date, event)) {
                                cout << "Deleted successfully" << endl;
                            } else {
                                cout << "Event not found" << endl;
                            }
                        } else {
                            cout << "Deleted " << DB.DeleteDate(date) << " events" << endl;
                        }
                    }
                } else {
                    stringstream ss;
                    ss << "Unknown command: " << com;
                    throw runtime_error(ss.str());
                }
            }
        }
    } catch (exception& ex) {
        cout << ex.what() << endl;
    }
    return 0;
}