#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  std::cout << "vector: ";
  for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
  std::cout << "\n\n";

  std::cout << "[test with easyfind(v, 3)]\n";
  std::vector<int>::iterator it = easyfind(v, 3);
  std::cout << "  Found at index: " << std::distance(v.begin(), it) << "\n\n";

  try {
    std::cout << "[test with easyfind(v, 6)]\n";
    easyfind(v, 6);
  } catch (const std::exception &e) {
    std::cout << "  caught error: " << e.what() << "\n";
  }

  return 0;
}
