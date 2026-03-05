#include "node.h"

using namespace std;

template<typename T>
bool Compare(const T& left, Comparison cmp, const T& right) {
    switch (cmp) {
        case Comparison::Less: return left < right;
        case Comparison::LessOrEqual: return left <= right;
        case Comparison::Greater: return left > right;
        case Comparison::GreaterOrEqual: return left >= right;
        case Comparison::Equal: return left == right;
        case Comparison::NotEqual: return left != right;
        default: return false;
    }
}

bool EmptyNode::Evaluate(const Date&, const std::string&) const {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string&) const {
    return Compare(date, cmp_, date_);
}

bool EventComparisonNode::Evaluate(const Date&, const string& event) const {
    return Compare(event, cmp_, event_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    switch(op_) {
        case LogicalOperation::And: return left_->Evaluate(date, event) && right_->Evaluate(date, event);
        case LogicalOperation::Or: return left_->Evaluate(date, event) || right_->Evaluate(date, event);
        default: return false;
    }
}
