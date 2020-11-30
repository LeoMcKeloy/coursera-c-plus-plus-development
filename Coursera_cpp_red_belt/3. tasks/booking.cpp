#include <iostream>
#include <set>
#include <string>
#include <queue>
#include <map>
#include <deque>
#include <cstdint>

using namespace std;

class BookingManager {
public:
    void Book(const uint64_t& time, const string& hotel_name,
              const unsigned int& client_id, const int64_t& room_count) {
        while (time_books.front().second + 86400 <= time && !time_books.empty()) {
            if (time_books.front().second + 86400 <= time) {
                if (hotel_rooms.count(time_books.front().first) != 0) {

                    hotel_rooms[time_books.front().first].pop_front();
                }
                if (hotel_clients.count(time_books.front().first) != 0) {

                    hotel_clients[time_books.front().first].pop_front();
                }
            }
            time_books.pop();
        }
        time_books.push(make_pair(hotel_name, time));
        hotel_clients[hotel_name].push_back(client_id);
        hotel_rooms[hotel_name].push_back(room_count);
    }

    int Clients(const string& hotel_name) {
        if (hotel_clients[hotel_name].empty()) {
            return 0;
        }
        int count = 0;
        for (unsigned int& i : hotel_clients[hotel_name]) {
            count += 1;
        }
        return count;
    }

    int Rooms(const string& hotel_name) {
        if (hotel_rooms[hotel_name].empty()) {
            return 0;
        }
        int count = 0;
        for (int64_t & i : hotel_rooms[hotel_name]) {
            count += i;
        }
        return count;
    }

private:
    map<string, deque<unsigned int>> hotel_clients;
    map<string, deque<int64_t>> hotel_rooms;
    queue<pair<string, uint64_t>> time_books;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BookingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;

        if (query_type == "BOOK") {
            int time;
            string hotel_name;
            int client_id;
            int room_count;
            cin >> time >> hotel_name >> client_id >> room_count;
            manager.Book(time, hotel_name, client_id, room_count);
        } else if (query_type == "CLIENTS") {
            string hotel_name;
            cin >> hotel_name;
            cout << manager.Clients(hotel_name) << "\n";
        } else if (query_type == "ROOMS") {
            string hotel_name;
            cin >> hotel_name;
            cout << manager.Rooms(hotel_name) << "\n";
        }
    }
    return 0;
}