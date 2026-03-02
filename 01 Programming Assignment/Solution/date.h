#pragma once

#include <iostream>
#include <iomanip>
#include <tuple>

using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

Date ParseDate(istream& is);

ostream& operator<<(ostream& os, const Date& date);
bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
