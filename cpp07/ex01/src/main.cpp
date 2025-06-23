#include "iter.hpp"
#include <iostream>

void inc(int &x) {
  ++x;
  std::cout << x << ' ';
}

void print(const int &x) { std::cout << x << ' '; }

int main() {
  int arr[5];
  const int arr_const[5] = {1, 2, 3, 4, 5};

  for (int i = 0; i < 5; ++i)
    arr[i] = i + 1;

  std::cout << "non-const array and const function: \n";
  iter(arr, 5, print);
  std::cout << std::endl;

  std::cout << "non-const array and non-const function: \n";
  iter(arr, 5, inc);
  std::cout << std::endl;

  std::cout << "const array and const function: \n";
  iter(arr_const, 5, print);
  std::cout << std::endl;

  // std::cout << "const array and non-const function:(cannot compile) ";
  // iter(arr_const, 5, inc);
  // std::cout << std::endl;

  return 0;
}
