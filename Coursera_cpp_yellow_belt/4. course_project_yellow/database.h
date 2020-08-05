#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include "date.h"


class Database {
public:
    void Add(const Date& date, const std::string& event);
    void Print(std::ostream& os) const;

    template <typename Predicate>
    int RemoveIf(const Predicate& predicate) {
        int result = 0;
        std::vector<Date> entries_to_delete = {};

        for(auto& entry : entries) {
            std::vector<std::string> new_events = {};

            for (const std::string& event : entry.second) {
                if (predicate(entry.first, event)) {
                    result++;
                    entries_set[entry.first].erase(event);
                } else {
                    new_events.push_back(event);
                }
            }

            if(new_events.size() == 0) {
                entries_to_delete.push_back(entry.first);
            } else {
                entry.second = new_events;
            }
        }

        for (const auto& date : entries_to_delete) {
            entries.erase(date);
            entries_set.erase(date);
        }

        return result;
    }

    template <typename Predicate>
    std::vector<std::pair<Date, std::string>> FindIf(const Predicate& predicate) const {
        std::vector<std::pair<Date, std::string>> result = {};

        for(const auto& entry : entries) {
            for (const std::string& event : entry.second) {
                if (predicate(entry.first, event)) {
                    result.push_back(make_pair(entry.first, event));
                }
            }
        }

        return result;
    };

    std::pair<Date, std::string> Last(const Date& date) const;

private:
    std::map<Date, std::vector<std::string>> entries;
    std::map<Date, std::set<std::string>> entries_set;
};

// Tests
void TestDatabaseAddAndPrint();
void TestDatabaseFind();
void TestDatabaseRemove();
void TestDatabaseLast();