#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
public:
  Span();
  Span(unsigned int N);
  ~Span();
  Span(const Span &other);
  Span &operator=(const Span &other);

  void addNumber(int number);
  void addNumber(std::vector<int>::iterator begin,
                 std::vector<int>::iterator end);
  unsigned int shortestSpan();
  unsigned int longestSpan();

private:
  std::vector<int> numbers_;
  unsigned int N_;
};

#endif
