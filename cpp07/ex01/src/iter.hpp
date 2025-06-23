#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <stdexcept>

template <typename T, typename F> void iter(T *array, size_t length, F f) {
  if (!array)
    throw std::runtime_error("iter: array or function is null");
  for (size_t i = 0; i < length; i++) {
    f(array[i]);
  }
}

#endif
