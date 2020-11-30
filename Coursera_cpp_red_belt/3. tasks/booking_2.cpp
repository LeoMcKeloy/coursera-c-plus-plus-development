#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include "test_runner.h"
#include <queue>

using namespace std;

struct Event {
    int64_t time;
    string hotel;
    int client;
    int rooms_count;
};


class BookingManager {
public:
    BookingManager() : current_time(0) {}

    void Book(const int64_t& time, const string& hotel_name,
              const int& client_id, const int& room_count) {
        current_time = time;

        if (events.empty()) {
            inserter(time, hotel_name, client_id, room_count);
        } else {
            deleter(time, hotel_name, client_id, room_count);
            inserter(time, hotel_name, client_id, room_count);
        }
    }

    int64_t Clients(const string& hotel_name) const {
        if (hotel_to_clients.count(hotel_name) == 0) {
            return 0;
        }
        return hotel_to_clients.at(hotel_name).size();
    }

    int64_t Rooms(const string& hotel_name) const {
        if (hotel_to_rooms.count(hotel_name) == 0) {
            return 0;
        }
        return hotel_to_rooms.at(hotel_name);
    }

private:
    int64_t current_time;
    queue<Event> events;
    unordered_map<string, unordered_set<int>> hotel_to_clients;
    unordered_map<string, int> hotel_to_rooms;

    void inserter(const int64_t& time, const string& hotel_name,
                  const int& client_id, const int& room_count) {
        events.push({ time, hotel_name, client_id, room_count });
        hotel_to_clients[hotel_name].insert(client_id);
        hotel_to_rooms[hotel_name] += room_count;
    }

    void deleter(const int64_t& time, const std::string& hotel_name,
                 const int& client_id, const int& room_count) {
        auto event = events.front();

        while (event.time <= (current_time - sec) && !events.empty()) {
            hotel_to_clients.at(event.hotel).erase(event.client);
            hotel_to_rooms.at(event.hotel) -= event.rooms_count;
            events.pop();
            event = events.front();
        }
    }

    static const int64_t sec = 86400;
};


void test() {
    BookingManager manager;

    // Test empty bookings
    ASSERT_EQUAL(manager.Clients("mariott"), 0);
    ASSERT_EQUAL(manager.Rooms("mariott"), 0);

    manager.Book(0, "mariott", 1, 10);
    manager.Book(0, "mariott", 2, 1);
    manager.Book(0, "mariott", 3, 1);
    manager.Book(0, "mariott", 4, 1);
    manager.Book(0, "hilton", 1, 1);
    manager.Book(1, "hilton", 2, 1);

    // Test correctness
    ASSERT_EQUAL(manager.Clients("mariott"), 4);
    ASSERT_EQUAL(manager.Rooms("mariott"), 13);
    ASSERT_EQUAL(manager.Clients("hilton"), 2);
    ASSERT_EQUAL(manager.Rooms("hilton"), 2);

    // Test event past 1 day resets statics
    manager.Book(86400, "mariott", 1, 1);
    ASSERT_EQUAL(manager.Clients("mariott"), 1);
    ASSERT_EQUAL(manager.Rooms("mariott"), 1);
    ASSERT_EQUAL(manager.Clients("hilton"), 1);
    ASSERT_EQUAL(manager.Rooms("hilton"), 1);

    // Test no clients and room for the last day
    manager.Book(86401, "mariott", 5, 1);
    ASSERT_EQUAL(manager.Clients("mariott"), 2);
    ASSERT_EQUAL(manager.Rooms("mariott"), 2);
    ASSERT_EQUAL(manager.Clients("hilton"), 0);
    ASSERT_EQUAL(manager.Rooms("hilton"), 0);

    manager = BookingManager();
    manager.Book(1, "A", 1, 1);
    manager.Book(2, "A", 1, 1);
    manager.Book(3, "A", 1, 1);
    ASSERT_EQUAL(manager.Clients("A"), 1);
    ASSERT_EQUAL(manager.Rooms("A"), 3);

    // Test from example
    manager = BookingManager();
    ASSERT_EQUAL(manager.Clients("Marriott"), 0);
    ASSERT_EQUAL(manager.Rooms("Marriott"), 0);
    manager.Book(10, "FourSeasons", 1, 2);
    manager.Book(10, "Marriott", 1, 1);
    manager.Book(86409, "FourSeasons", 2, 1);
    ASSERT_EQUAL(manager.Clients("FourSeasons"), 2);
    ASSERT_EQUAL(manager.Rooms("FourSeasons"), 3);
    ASSERT_EQUAL(manager.Clients("Marriott"), 1);
    manager.Book(86410, "Marriott", 2, 10);
    ASSERT_EQUAL(manager.Rooms("FourSeasons"), 1);
    ASSERT_EQUAL(manager.Rooms("Marriott"), 10);
}


void TestManager() {
    TestRunner tr;
    RUN_TEST(tr, test);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    TestManager();
    BookingManager hotel_manager;
    int q;
    string command, hotel_name;
    int64_t time;
    int client_id;
    int room_count;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> command;
        if (command == "BOOK") {
            std::cin >> time >> hotel_name >> client_id >> room_count;
            hotel_manager.Book(time, hotel_name, client_id, room_count);
        }
        if (command == "CLIENTS") {
            std::cin >> hotel_name;
            std::cout << hotel_manager.Clients(hotel_name) << "\n";
        }
        if (command == "ROOMS") {
            std::cin >> hotel_name;
            std::cout << hotel_manager.Rooms(hotel_name) << "\n";
        }
    }
    return 0;
}