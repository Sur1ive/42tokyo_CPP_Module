#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

void big_fill_test() {
  const unsigned int SIZE = 12000;
  Span sp(SIZE);

  std::vector<int> buf;
  buf.reserve(SIZE);
  srand(time(NULL));

  for (unsigned int i = 0; i < SIZE; ++i)
    buf.push_back(std::rand());

  sp.addNumber(buf.begin(), buf.end());

  std::cout << "[test with 12000 random numbers]\n";
  std::cout << "  shortestSpan = " << sp.shortestSpan() << '\n';
  std::cout << "  longestSpan  = " << sp.longestSpan() << '\n';
}

void overflow_test() {
  Span sp(5);
  for (int i = 0; i < 5; ++i)
    sp.addNumber(i);

  std::cout << "\n[overflow test]\n";
  try {
    sp.addNumber(5);
  } catch (const std::exception &e) {
    std::cout << "  caught error: " << e.what() << '\n';
  }
}

void insufficient_test() {
  Span sp(3);

  std::cout << "\n[insufficient data test]\n";
  try {
    sp.shortestSpan();
  } catch (const std::exception &e) {
    std::cout << "  caught error: " << e.what() << '\n';
  }

  sp.addNumber(42);
  try {
    sp.longestSpan();
  } catch (const std::exception &e) {
    std::cout << "  caught error: " << e.what() << '\n';
  }
}

int main() {
  big_fill_test();
  overflow_test();
  insufficient_test();
  return 0;
}
