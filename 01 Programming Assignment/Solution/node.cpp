#include "node.h"

using namespace std;

template <typename T>
bool Compare(const T& left, const Comparison& cmp, const T& right) {
    switch (cmp) {
        case Comparison::Less:
            return left < right;
        case Comparison::LessOrEqual:
            return left <= right;
        case Comparison::Greater:
            return left > right;
        case Comparison::GreaterOrEqual:
            return left >= right;
        case Comparison::Equal:
            return left == right;
        case Comparison::NotEqual:
            return left != right;
        default:
            return 0;
            break;
    }
}

EmptyNode::EmptyNode() {}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& comparison, const Date& date) : cmp(comparison), dt(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(date, cmp, dt);
}

EventComparisonNode::EventComparisonNode(const Comparison& comparison, const string& event) : cmp(comparison), ev(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(event, cmp, ev);
}
