#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

// Interface

template <class K, class V>
ostream& operator<<(ostream& out, const map<K, V>& m);

template <class T>
ostream& operator<<(ostream& out, const set<T>& s);

template <class T>
ostream& operator<<(ostream& out, const vector<T>& s);

template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint);

void Assert(bool b, const string& hint);

class TestRunner {
private:
    int fail_count = 0;
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name);

    ~TestRunner();
};

// Implemetation

template <class K, class V>
ostream& operator<<(ostream& out, const map<K, V>& m) {
    out << "{";
    bool first = true;

    for (const auto& kv : m) {
        if (!first) {
            out << ", ";
        }
        first = false;
        out << kv.first << ": " << kv.second;
    }

    return out << "}";
}

template <class T>
ostream& operator<<(ostream& out, const set<T>& s) {
    out << "{";
    bool first = true;

    for (const auto& x : s) {
        if (!first) {
            out << ", ";
        }
        first = false;
        out << x;
    }

    return out << "}";
}

template <class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    out << "{";
    bool first = true;

    for (const auto& x : v) {
        if (!first) {
            out << ", ";
        }
        first = false;
        out << x;
    }

    return out << "}";
}


template <class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << " Hint: " << hint;

        throw runtime_error(os.str());
    }
}

template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const string& test_name) {
    try {
        func();
        cerr << test_name << " OK" << endl;
    } catch (runtime_error& e) {
        ++fail_count;
        cerr << test_name << " fail: " << e.what() << endl;
    }
}

#define ASSERT_EQUAL(x, y) {                \
    ostringstream os;                       \
    os << #x << " != " << #y << ", "        \
        << __FILE__ << ":" << __LINE__;     \
    AssertEqual(x, y, os.str());            \
}

#define ASSERT(x) {                         \
    ostringstream os;                       \
    os << #x << " is false, "               \
        << __FILE__ << ":" << __LINE__;     \
    Assert(x, os.str());                    \
}

#define RUN_TEST(tr, func)                  \
    tr.RunTest(func, #func)
