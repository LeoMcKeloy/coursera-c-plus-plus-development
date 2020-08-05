#pragma once
#include <sstream>
#include <set>
#include <tuple>
#include <iomanip>


class Date {
public:
    Date(const int& y, const int& m, const int& d) : year(y), month(m), day(d) {}
    const int year;
    const int month;
    const int day;
};

Date ParseDate(std::istream&);

inline std::ostream& operator << (std::ostream& os, const Date& date) {
    os << std::setfill('0') << std::setw(4) << date.year << '-' <<
    std::setw(2) << date.month << '-' << std::setw(2) << date.day;

    return os;
}

inline std::ostream& operator << (std::ostream& os, const std::pair<Date, std::string>& pair) {
    os << pair.first << " " << pair.second;

    return os;
}

inline bool operator==(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) == std::tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator!=(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) != std::tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator>(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) > std::tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator<(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) < std::tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator>=(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) >= std::tie(rhs.year, rhs.month, rhs.day);
}

inline bool operator<=(const Date& lhs, const Date& rhs) {
    return std::tie(lhs.year, lhs.month, lhs.day) <= std::tie(rhs.year, rhs.month, rhs.day);
}

// Test
void TestDateOutput();
void TestParseDate();