#include "Array.hpp"
#include <iostream>

int main() {
  try {
    Array<int> a0;
    std::cout << "a0.size = " << a0.size() << '\n';

    Array<int> a5(5);
    for (unsigned int i = 0; i < a5.size(); ++i)
      a5[i] = i * 10;
    std::cout << "a5: ";
    for (unsigned int i = 0; i < a5.size(); ++i)
      std::cout << a5[i] << ' ';
    std::cout << std::endl;

    Array<int> a5_copy(a5);
    a5_copy[0] = 99;
    std::cout << "a5[0] = " << a5[0] << ", a5_copy[0] = " << a5_copy[0]
              << std::endl;

    Array<int> a5_copy2;
    a5_copy2 = a5;
    a5_copy2[1] = 88;
    std::cout << "a5[1] = " << a5[1] << ", a5_copy2[1] = " << a5_copy2[1]
              << std::endl;

    std::cout << "try out-of-range" << std::endl;
    a5[123] = 0;
  } catch (const std::exception &) {
    std::cout << "Caught out-of-range exception!" << std::endl;
  }
  return 0;
}
