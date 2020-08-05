#pragma once
#include <iostream>
#include <memory>
#include "date.h"

enum class Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};

enum class LogicalOperation {
    And,
    Or
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const std::string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const std::string& event) const override;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperationNode(const LogicalOperation& o, const std::shared_ptr<Node>& l, const std::shared_ptr<Node> r);
    bool Evaluate(const Date& date, const std::string& event) const override;
    const LogicalOperation logical_operation;
    const std::shared_ptr<Node> left, right;
};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(const Comparison& c, const std::string& e);
    bool Evaluate(const Date& date, const std::string& event) const override;
    const Comparison comp;
    const std::string event;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(const Comparison& c, const Date& d);
    bool Evaluate(const Date& date, const std::string& event) const override;
    const Comparison comp;
    const Date date;
};

// Tests
void TestDateComparisonNode();
void TestEventComparisonNode();
void TestLogicalOperationNode();