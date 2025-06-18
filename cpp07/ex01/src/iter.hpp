#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename R>
void iter(T *array, size_t length, R (*f)(T &)) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

template <typename T, typename R>
void iter(T *array, size_t length, R (*f)(const T &)) {
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

#endif
