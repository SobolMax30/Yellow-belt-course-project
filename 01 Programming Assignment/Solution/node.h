#pragma once

#include "date.h"

#include <memory>

using namespace std;

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
bool Compare(const T& left, const Comparison& cmp, const T& right);

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : Node {
public:
    EmptyNode();
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : Node {
private:
    Comparison cmp;
    Date dt;
public:
    DateComparisonNode(const Comparison& comparison, const Date& date);
    bool Evaluate(const Date& date, const string& event) const override;
};


class EventComparisonNode : Node {
private:
    Comparison cmp;
    string ev;
public:
    EventComparisonNode(const Comparison& comparison, const string& event);
    bool Evaluate(const Date& date, const string& event) const override;
};

class LogicalOperationNode : Node {
    bool Evaluate(const Date& date, const string& event) const override;
};

