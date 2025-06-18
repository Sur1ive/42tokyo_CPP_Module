#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T> class Array {
public:
  Array() : array_(new T[0]), size_(0) {};
  Array(unsigned int n) : array_(new T[n]), size_(n) {};
  Array(const Array &other) : array_(new T[other.size_]), size_(other.size_) {
    for (unsigned int i = 0; i < size_; i++) {
      array_[i] = other.array_[i];
    }
  };
  ~Array() { delete[] array_; };

  Array &operator=(const Array &other) {
    if (this == &other) {
      return *this;
    }
    delete[] array_;
    array_ = new T[other.size_];
    size_ = other.size_;
    for (unsigned int i = 0; i < size_; i++) {
      array_[i] = other.array_[i];
    }
    return *this;
  };

  T &operator[](const unsigned int &index) const {
    if (index >= size_) {
      throw std::exception();
    }
    return array_[index];
  };

  unsigned int size() const { return size_; };

private:
  T *array_;
  unsigned int size_;
};

#endif
