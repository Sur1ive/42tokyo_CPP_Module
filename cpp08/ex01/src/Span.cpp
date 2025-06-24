#include "Span.hpp"
#include <algorithm>
#include <stdexcept>

Span::Span() : N_(0) {}

Span::Span(unsigned int N) : N_(N) {}

Span::~Span() {}

Span::Span(const Span &other) : numbers_(other.numbers_), N_(other.N_) {}

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    N_ = other.N_;
    numbers_ = other.numbers_;
  }
  return *this;
}

void Span::addNumber(int number) {
  if (numbers_.size() >= N_)
    throw std::runtime_error("Span is full");
  numbers_.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin,
                     std::vector<int>::iterator end) {
  if (numbers_.size() + std::distance(begin, end) > N_)
    throw std::runtime_error("Span is full");
  numbers_.insert(numbers_.end(), begin, end);
}

unsigned int Span::shortestSpan() const {
  if (numbers_.size() < 2)
    throw std::runtime_error("Not enough numbers to find shortest span");

  int shortest = abs(numbers_[1] - numbers_[0]);
  for (unsigned int i = 0; i < numbers_.size() - 1; i++) {
    if (abs(numbers_[i + 1] - numbers_[i]) < shortest)
      shortest = abs(numbers_[i + 1] - numbers_[i]);
  }
  return shortest;
}

unsigned int Span::longestSpan() const {
  if (numbers_.size() < 2)
    throw std::runtime_error("Not enough numbers to find longest span");
  return *std::max_element(numbers_.begin(), numbers_.end()) -
         *std::min_element(numbers_.begin(), numbers_.end());
}
