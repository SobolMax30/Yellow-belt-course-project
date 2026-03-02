#include "date.h"

using namespace std;

Date::Date() : year(0), month(0), day(0) {}
Date::Date(int new_year, int new_month, int new_day) {
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid " + to_string(new_month));
    } else {
        month = new_month;
    }

    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid " + to_string(new_day));
    } else {
        day = new_day;
    }

    year = new_year;
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

Date ParseDate(istream& is) {
    int year, month, day;

    is >> year;
    is.ignore(1);
    is >> month;
    is.ignore(1);
    is >> day;

    return Date{year, month, day};
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.GetYear() << '-'
         << setw(2) << setfill('0') << date.GetMonth() << '-'
         << setw(2) << setfill('0') << date.GetDay();

    return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator<=(const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>(const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) > make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator>=(const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator==(const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) == make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) != make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
