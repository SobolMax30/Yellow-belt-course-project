#pragma once

#include "date.h"

#include <memory>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual,
};

enum class LogicalOperation {
    Or,
    And,
};

template <typename T>
bool Compare(const T& left, const Comparison& comparison, const T& right) {
    switch (comparison) {
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
            return false;
    }
}

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
private:
    Comparison comparison_;
    Date date_;
public:
    DateComparisonNode(const Comparison& comparison, const Date& date);
    bool Evaluate(const Date& date, const std::string& event) const override;
};


class EventComparisonNode : public Node {
private:
    Comparison comparison_;
    std::string event_;
public:
    EventComparisonNode(const Comparison& comparison, const std::string& event);
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class LogicalOperationNode : public Node {
private:
    LogicalOperation logical_operation_;
    std::shared_ptr<Node> left_node_, right_node_;
public:
    LogicalOperationNode(const LogicalOperation& logical_operation, const std::shared_ptr<Node>& left_node, const std::shared_ptr<Node>& right_node);
    bool Evaluate(const Date& date, const std::string& event) const override;
};

