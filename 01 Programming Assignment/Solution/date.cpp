#include "date.h"

#include <iomanip>
#include <tuple>

bool Date::operator<(const Date& other) const {
    return tie(year, month, day) < tie(other.year, other.month, other.day);
}

bool Date::operator<=(const Date& other) const {
    return tie(year, month, day) <= tie(other.year, other.month, other.day);
}

bool Date::operator>(const Date& other) const {
    return tie(year, month, day) > tie(other.year, other.month, other.day);
}

bool Date::operator>=(const Date& other) const {
    return tie(year, month, day) >= tie(other.year, other.month, other.day);
}

bool Date::operator==(const Date& other) const {
    return tie(year, month, day) == tie(other.year, other.month, other.day);
}

bool Date::operator!=(const Date& other) const {
    return tie(year, month, day) != tie(other.year, other.month, other.day);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setfill('0') << setw(4) << date.year << '-'
         << setw(2) << date.month << '-'
         << setw(2) << date.day;

    return os;
}

Date ParseDate(istream& is) {
    int year, month, day;
    char separator;

    if (is >> year >> separator >> month >> separator >> day) {
        return Date{year, month, day};
    } else {
        throw invalid_argument("Wrond Date format");
    }
}


