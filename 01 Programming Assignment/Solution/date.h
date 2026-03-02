#pragma once

#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;

    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
};

ostream& operator<<(ostream& os, const Date& date);

Date ParseDate(istream& is);
