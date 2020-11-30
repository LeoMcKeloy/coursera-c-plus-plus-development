#include "test_runner.h"
#include "profile.h"

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

template<typename T>
class Table {
public:
    Table(size_t rows, size_t columns) {
        Resize(rows, columns);
    }

    vector<T>& operator[] (size_t index) {
        return data[index];
    }
    const vector<T>& operator[] (size_t index) const {
        return data[index];
    }

    void Resize(size_t rows, size_t columns) {
        data.resize(rows);
        for (auto& item : data) {
            item.resize(columns);
        }
    }

    pair<size_t, size_t> Size() const {
        return {data.size(), (data.empty() ? 0 : data[0].size())};
    }
private:
    size_t row_, column_;
    vector<vector<T>> data;
};

void TestTable() {
  Table<int> t(1, 1);
  ASSERT_EQUAL(t.Size().first, 1u);
  ASSERT_EQUAL(t.Size().second, 1u);
  t[0][0] = 42;
  ASSERT_EQUAL(t[0][0], 42);
  t.Resize(3, 4);
  ASSERT_EQUAL(t.Size().first, 3u);
  ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    LOG_DURATION("Total");
  TestRunner tr;
  RUN_TEST(tr, TestTable);
  return 0;
}