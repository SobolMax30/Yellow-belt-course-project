#pragma once

#include "comparison.h"
#include "date.h"

using namespace std;

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : Node {
public:
    bool Evaluate(const Date&, const string&) const override {
        return true;
    }
};

class DateComparisonNode : Node {
public:
    bool Evaluate(const Date& date, const string&) const override {

    }
};


class EventComparisonNode : Node {
public:
    bool Evaluate(const Date&, const string& event) const override {

    }
};

class LogicalOperationNode : Node {
public:
    bool Evaluate(const Date& date, const string& event) const override {

    }
};
