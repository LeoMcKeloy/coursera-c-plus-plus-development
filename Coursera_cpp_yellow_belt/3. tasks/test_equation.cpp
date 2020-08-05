#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

int GetDistinctRealRootCount(double a, double b, double c);

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
    double d;

    if (a != 0 && b == 0 && c == 0)
        return 1;
    if (a == 0 && b != 0 && c == 0)
        return 1;
    if (a != 0 && b != 0 && c == 0)
        return 2;
    if (a != 0 && b == 0 && c != 0) {
        if (-c / a > 0) {
            return 2;
        }
    }
    if (a == 0 && b != 0 && c != 0)
        return 1;
    if (a != 0 && b != 0 && c != 0) {
        d = b * b - 4 * a * c;
        if (d == 0) {
            return 1;
        } else if (d > 0) {
            return 2;
        }
    } else return 0;
}

void Tests() {
    AssertEqual(GetDistinctRealRootCount(1, 0, 0), 1, "a != 0, b == 0, c == 0");
    AssertEqual(GetDistinctRealRootCount(0, 5, 0), 1, "a == 0, b != 0, c == 0");
    AssertEqual(GetDistinctRealRootCount(1, 2, 0), 2, "a != 0, b != 0, c == 0");
    AssertEqual(GetDistinctRealRootCount(1, 0, -4), 2, "a != 0, b == 0, c != 0");
    AssertEqual(GetDistinctRealRootCount(1, 0, 4), 0, "a != 0, b == 0, c != 0 && (-c / a) < 0");
    AssertEqual(GetDistinctRealRootCount(0, 3, 4), 1, "a == 0, b != 0, c != 0");
    AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, "Discriminant < 0");
    AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "Degenerate case");
    AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, "Discriminant == 0");
}

int main() {
    TestRunner runner;
    runner.RunTest(Tests, "Tests");
    return 0;
}