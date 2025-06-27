#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN {
public:
  static int evaluate(const std::string &expression);

private:
  RPN();
  ~RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);

  static bool isValidExpression(const std::string &expression);
};

#endif
