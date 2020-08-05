#include "phone_number.h"
#include <exception>
#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number) {
    istringstream ss(international_number);

    char s = ss.get();
    getline(ss, country_code_, '-');
    getline(ss, city_code_, '-');
    getline(ss, local_number_);

    if (s != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
        throw invalid_argument("invalid_argument");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}