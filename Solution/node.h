#pragma once

#include "date.h"

#include <memory>
#include <functional>

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    Or,
    And
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class DateComparisonNode : public Node {
    Comparison cmp_;
    Date date_;
public:
    DateComparisonNode(Comparison cmp, Date date) : cmp_(cmp), date_(date) {}
    bool Evaluate(const Date& date, const std::string&) const override;
};

class EventComparisonNode : public Node {
    Comparison cmp_;
    std::string event_;
public:
    EventComparisonNode(Comparison cmp, std::string event) : cmp_(cmp), event_(event) {}
    bool Evaluate(const Date&, const std::string& event) const override;
};

class LogicalOperationNode : public Node {
    LogicalOperation op_;
    std::shared_ptr<Node> left_, right_;
public:
    LogicalOperationNode(LogicalOperation op, std::shared_ptr<Node> left, std::shared_ptr<Node> right)
        : op_(op), left_(left), right_(right) {}
    bool Evaluate(const Date& date, const std::string& event) const override;
};
