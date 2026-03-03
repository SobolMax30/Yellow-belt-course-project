#pragma once

#include "date.h"

#include <iostream>
#include <vector>
#include <map>

class Database {
private:
    std::map<Date, std::vector<std::string>> storage;
public:
    void Add(const Date& date, const std::string& event);

    void Print(std::ostream& os) const;

    template <typename Predicate>
    int RemoveIf(Predicate predicate);

    template <typename Predicate>
    std::vector<std::pair<Date, std::string>> FindIf(Predicate predicate) const;

    std::string Last(const Date& date) const;
};

template <typename Predicate>
int Database::RemoveIf(Predicate predicate) {
    // тело метода
}

template <typename Predicate>
std::vector<std::pair<Date, std::string>> Database::FindIf(Predicate predicate) const {
    // тело метода
}
