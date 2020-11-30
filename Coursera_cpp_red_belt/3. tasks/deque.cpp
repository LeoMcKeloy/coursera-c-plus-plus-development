#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Deque {
public:
    Deque() = default;

    bool Empty() const {
        return front.empty() && back.empty();
    }

    size_t Size() const {
        return front.size() + back.size();
    }

    T& operator[](size_t index) {
        if (index < front.size()) {
            return front[front.size() - 1 - index];
        } else {
            return back[index - front.size()];
        }
    }

    const T& operator[](size_t index) const {
        if (index < front.size()) {
            return front[front.size() - 1 - index];
        } else {
            return back[index - front.size()];
        }
    }

    T& At(size_t index) {
        if (index >= front.size() + back.size()) {
            throw out_of_range("Index is out of range");
        }
        if (index < front.size()) {
            return front[front.size() - 1 - index];
        }
        return back[index - front.size()];
    }

    const T& At(size_t index) const {
        if (index >= front.size() + back.size()) {
            throw out_of_range("Index out of range");
        }
        if (index < front.size()) {
            return front[front.size() - 1 - index];
        }
        return back[index - front.size()];
    }

    T& Front() {
        return front.empty() ? back.front() : front.back();
    }
    const T& Front() const {
        return front.empty() ? back.front() : front.back();
    }
    T& Back() {
        return back.empty() ? front.front() : back.back();
    }
    const T& Back() const {
        return back.empty() ? front.front() : back.back();
    }

    void PushFront(const T& element) {
        front.push_back(element);
    }

    void PushBack(const T& element) {
        back.push_back(element);
    }

private:
    vector<T> front;
    vector<T> back;
};