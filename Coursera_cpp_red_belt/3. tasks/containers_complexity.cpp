#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>

#include "profile.h"

using namespace std;
using namespace std::chrono;

int main() {
    {
        LOG_DURATION("Vector_insert_begin");
        vector<int> v;
        for (size_t i = 0; i < 100000; i++) {
            v.insert(v.begin(), i);
        }
    }
    {
        LOG_DURATION("Deque_insert_begin");
        deque<int> v;
        for (size_t i = 0; i < 100000; i++) {
            v.insert(v.begin(), i);
        }
    }
    {
        LOG_DURATION("Deque_push_front");
        deque<int> v;
        for (size_t i = 0; i < 100000; i++) {
            v.push_front(i);
        }
    }
    {
        LOG_DURATION("Vector");
        vector<int> v;
        for (size_t i = 0; i < 100000; i++) {
            v.push_back(i);
        }
    }
    {
        LOG_DURATION("Set");
        set<int> v;
        for (size_t i = 0; i < 100000; i++) {
            v.insert(i);
        }
    }
    {
        LOG_DURATION("Deque");
        deque<int> v;
        for (size_t i = 0; i < 100000; i++) {
            v.push_back(i);
        }
    }
    return 0;
}