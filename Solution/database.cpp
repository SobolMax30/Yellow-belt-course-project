#include "database.h"

using namespace std;

void Database::Add(const Date& date, const string& event) {
    vector<string>& events = storage[date];

    bool event_exists = false;

    for (const string& existing_event : events) {
        if (existing_event == event) {
            event_exists = true;
            break;
        }
    }

    if (!event_exists) {
        events.push_back(event);
    }
}

void Database::Print(ostream& os) const {
    for (const auto& [date, events] : storage) {
        for (const string& event: events) {
            os << date << " " << event << endl;
        }
    }
}

string Database::Last(const Date& date) const {
    return "asdads";
}
