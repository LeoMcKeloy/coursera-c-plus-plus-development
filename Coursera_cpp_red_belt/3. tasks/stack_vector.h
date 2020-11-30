#pragma once

#include <stdexcept>
#include <array>
#include <exception>
#include <iterator>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
  explicit StackVector(size_t a_size = 0)
        : size_(a_size),
          first_(arr.begin()) {
      if (a_size > N) {
          throw invalid_argument("Invalid argument");
      }
  }

  T& operator[](size_t index) {
      return arr[index];
  }
  const T& operator[](size_t index) const {
      return arr[index];
  }

  typename array<T, N>::iterator begin() {
      return first_;
  }

  typename array<T, N>::iterator end() {
      return last_;
  }
  typename array<T, N>::const_iterator begin() const {
      return first_;
  }
  typename array<T, N>::const_iterator end() const {
      return last_;
  }

  size_t Size() const {
      return size_;
  }
  size_t Capacity() const {
      return N;
  }

  void PushBack(const T& value) {
      if (Size() == Capacity()) {
          throw overflow_error("Overflow error");
      }
      arr[size_++] = value;
  }

  T PopBack() {
      if (Size() == 0) {
          throw underflow_error("Underflow error");
      }
      else {
          --size_;
          return arr[size_];
      }
  }

private:
    size_t size_;
    array<T, N> arr;
    typename array<T,N>::iterator first_;
    typename array<T,N>::iterator last_ = first_ + size_;
};

