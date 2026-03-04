#pragma once

#include <iostream>
#include <iomanip>
#include <tuple>

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date() : year(0), month(0), day(0) {}
    Date(int new_year, int new_month, int new_day);

    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

Date ParseDate(std::istream& is);

std::ostream& operator<<(std::ostream& os, const Date& date);
std::ostream& operator<<(std::ostream& os, const std::pair<Date, std::string>& date_event);

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);
