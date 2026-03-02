#pragma once

#include "date.h"

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Database {
private:
    map<Date, vector<string>> storage;
public:
    void Add(const Date& date, const string& event);

    void Print(ostream& os) const;

    template <typename Predicate>
    int RemoveIf(Predicate predicate);

    template <typename Predicate>
    vector<string> FindIf(Predicate predicate) const;

    string Last(const Date& date) const;
};
