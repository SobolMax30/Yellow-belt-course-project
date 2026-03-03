#include "date.h"

using namespace std;

Date::Date() : year(0), month(0), day(0) {}
Date::Date(int new_year, int new_month, int new_day) {
    if (new_month > 12 || new_month < 1) {
        throw logic_error("Month value is invalid: " + to_string(new_month));
    } else {
        month = new_month;
    }

    if (new_day > 31 || new_day < 1) {
        throw logic_error("Day value is invalid: " + to_string(new_day));
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
    string date_str;
    is >> date_str;

    stringstream stream(date_str);

    int year = -1;
    stream >> year;

    if (stream.fail() || stream.peek() != '-') {
        throw logic_error("Wrong date format: " + date_str);
    }
    stream.ignore();

    int month = -1;
    stream >> month;

    if (stream.fail() || stream.peek() != '-') {
        throw logic_error("Wrong date format: " + date_str);
    }
    stream.ignore();

    int day = -1;
    stream >> day;

    if (stream.fail() || !stream.eof()) {
        throw logic_error("Wrong date format: " + date_str);
    }

    return Date(year, month, day);
}

ostream& operator<<(ostream& os, const Date& date) {
    os << setw(4) << setfill('0') << date.GetYear() << '-'
         << setw(2) << setfill('0') << date.GetMonth() << '-'
         << setw(2) << setfill('0') << date.GetDay();

    return os;
}

ostream& operator<<(ostream& os, const pair<Date, string>& date_event) {
    os << date_event.first << " " << date_event.second;

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
