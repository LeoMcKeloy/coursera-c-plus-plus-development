#pragma once

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

    SimpleVector(const SimpleVector& other)
            : data(new T[other.capacity_]),
              size_(other.size_),
              capacity_(other.capacity_) {
        copy(other.begin(), other.end(), begin());
    }

    ~SimpleVector() {
        delete[] data;
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

    T &operator[](size_t index) {
        return data[index];
    };

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

    void PushBack(const T &value) {
        if (Size() >= Capacity()) {
            if (capacity_ != 0) {
                capacity_ *= 2;
            } else {
                capacity_ = 2;
            }
            T* tmp = new T[capacity_];
            for (size_t i = 0; i < size_; i++) {
                tmp[i] = data[i];
            }
            delete[] data;
            data = tmp;
            data[size_++] = value;
        } else {
            data[size_++] = value;
        }

    }

private:
    T *data = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;
};