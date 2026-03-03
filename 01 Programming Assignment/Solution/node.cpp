#include "node.h"

using namespace std;

EmptyNode::EmptyNode() {}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& comparison, const Date& date) : comparison_(comparison), date_(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(date, comparison_, date_);
}

EventComparisonNode::EventComparisonNode(const Comparison& comparison, const string& event) : comparison_(comparison), event_(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(event, comparison_, event_);
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logical_operation, const shared_ptr<Node>& left_node, const shared_ptr<Node>& right_node) :
    logical_operation_(logical_operation), left_node_(left_node), right_node_(right_node) {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    switch(logical_operation_) {
        case LogicalOperation::And:
            return left_node_->Evaluate(date, event) && right_node_->Evaluate(date, event);
        case LogicalOperation::Or:
            return left_node_->Evaluate(date, event) || right_node_->Evaluate(date, event);
        default:
            return false;
    }
}
