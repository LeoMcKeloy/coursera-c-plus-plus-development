#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class ReadingManager {
public:
    ReadingManager()
            : pages_users(MAX_PAGE_COUNT + 1)
    {}

    void Read(int user_id, int page_count) {
        if (users.count(user_id) == 0 ) {
            AddUser(user_id, page_count);
        } else {
            int prev_page = users[user_id];
            pages_users[prev_page].erase(user_id);
            AddUser(user_id, page_count);
        }

    }

    double Cheer(int user_id) {
        if (users.count(user_id) == 0) {
            return 0;
        }
        const int all = GetUserCount();

        if (all == 1) {
            return 1;
        }

        int page_base = users.at(user_id);
        int count = 0;
        for(int i=1; i<page_base; i++) {
            count += pages_users[i].size();
        }
        return (1.0 * count) / (all - 1);
    }


private:
    static const int MAX_PAGE_COUNT = 1000;
    map<int, int> users;
    vector<set<int>> pages_users;

    void AddUser(int user_id, int page_count) {
        users[user_id] = page_count;
        pages_users[page_count].insert(user_id);
    }

    int GetUserCount() const {
        return users.size();
    }
};

int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        } else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}