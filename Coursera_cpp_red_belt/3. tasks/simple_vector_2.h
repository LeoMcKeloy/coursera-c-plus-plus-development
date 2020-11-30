#pragma once

#include <cstdint>
#include <cstdlib>
#include <algorithm>
using namespace std;

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
    explicit SimpleVector(size_t size)
            : data(new T[size]),
              size_(size),
              capacity_(size)  {}

    ~SimpleVector() {
        delete[] data;
    }

    T &operator[](size_t index) {
        return data[index];
    };

    void operator=(const SimpleVector& other) {
        if (other.size_ <= capacity_) {
            copy(other.begin(), other.end(), begin());
            size_ = other.size_;
        } else {
            SimpleVector<T> tmp(other);
            swap(tmp.data, data);
            swap(tmp.size_, size_);
            swap(tmp.capacity_, capacity_);
        }
    }

    T *begin() {
        return data;
    }

    T *end() {
        return data + size_;
    }

    const T *begin() const {
        return data;
    }

    const T *end() const {
        return data + size_;
    }

    size_t Size() const {
        return size_;
    }

    size_t Capacity() const {
        return capacity_;
    }

    void PushBack(T value) {
        if (Size() >= Capacity()) {
            if (capacity_ != 0) {
                capacity_ *= 2;
            } else {
                capacity_ = 2;
            }
            T* tmp = new T[capacity_];
            move(begin(), end(), tmp);
            delete[] data;
            data = tmp;
            data[size_++] = move(value);
        } else {
            data[size_++] = move(value);
        }

    }

private:
    T *data = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};