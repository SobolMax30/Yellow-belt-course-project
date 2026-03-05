#pragma once

#include "date.h"

#include <iostream>
#include <algorithm>
#include <string>
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
    int count = 0;

    for (auto it = storage.begin(); it != storage.end(); ) {
        auto& date = it->first;
        auto& events = it->second;

        for (size_t i = 0; i < events.size(); ) {
            if (predicate(date, events[i])) {
                events.erase(events.begin() + i);
                ++count;
            } else {
                ++i;
            }
        }

        if (events.empty()) {
            it = storage.erase(it);
        } else {
            ++it;
        }
    }

    return count;
}

template <typename Predicate>
std::vector<std::pair<Date, std::string>> Database::FindIf(Predicate predicate) const {
    std::vector<std::pair<Date, std::string>> result;

    for (const auto& [date, events] : storage) {
        for (const std::string& event : events) {
            if (predicate(date, event)) {
                result.push_back({date, event});
            }
        }
    }

    return result;
}
