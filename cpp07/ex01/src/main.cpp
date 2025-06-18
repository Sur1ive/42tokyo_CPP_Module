#include "iter.hpp"
#include <iostream>

void inc(int &x) { ++x; }

void print(const int &x) { std::cout << x << ' '; }

int main() {
  int arr[5];
  for (int i = 0; i < 5; ++i)
    arr[i] = i + 1;

  std::cout << "Original : ";
  iter(arr, 5, print);
  std::cout << std::endl;

  iter(arr, 5, inc);

  std::cout << "After inc: ";
  iter(arr, 5, print);
  std::cout << std::endl;

  return 0;
}
