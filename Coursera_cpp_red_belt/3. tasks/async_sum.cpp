#include "profile.h"

#include <iostream>
#include <vector>
#include <future>
#include <numeric>

using namespace std;

vector<int> GenerateVector(int n) {
    vector<int> v;
    for (size_t i = 0; i < n; i++) {
        v.push_back(i);
    }
    return v;
}

int SumVector(const vector<int>& first, const vector<int>& second) {
    future<int> f1 = async([&first] {
        return accumulate(first.begin(), first.end(), 0);
    });
    future<int> f2 = async([&second] {
        return accumulate(second.begin(), second.end(), 0);
    });
    return f1.get() + f2.get();
}

int SumVector(const vector<int>& first, const vector<int>& second, int n) {
    future<int> f1 = async([&first, n] {
        return accumulate(first.begin(), first.end(), 0);
    });
    future<int> f2 = async([&second, n] {
        return accumulate(second.begin(), second.end(), 0);
    });
    return f1.get() + f2.get();
}

int main() {
    {
        LOG_DURATION("async")
        cout << SumVector(GenerateVector(1000000), GenerateVector(1000000)) << endl;
    }
}