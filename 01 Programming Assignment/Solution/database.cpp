#include "database.h"

void Database::Add(const Date& date, const string& event) {
    storage[date].push_back(event);
}

void Database::Print(ostream& os) const {
    for (const auto& [date, events] : storage) {
        for (const string& event: events) {
            os << date << " " << event << endl;
        }
    }
}

template <typename Predicate>
int Database::RemoveIf(Predicate pred) {

}
