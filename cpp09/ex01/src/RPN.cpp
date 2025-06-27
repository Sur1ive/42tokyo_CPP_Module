#include "RPN.hpp"
#include <climits>
#include <stack>
#include <stdexcept>

bool RPN::isValidExpression(const std::string &expression) {
  if (expression.empty())
    return false;
  for (size_t i = 0; i < expression.length(); i++) {
    if (i % 2 == 1 && expression[i] == ' ' && i != expression.length() - 1) {
      continue;
    }
    if (i % 2 == 0 &&
        (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' ||
         expression[i] == '/' || isdigit(expression[i]))) {
      continue;
    }
    return false;
  }
  return true;
}

int RPN::evaluate(const std::string &expression) {
  if (!isValidExpression(expression)) {
    throw std::runtime_error("Error: Invalid expression");
  }
  std::stack<int> stack;
  for (size_t i = 0; i < expression.length(); i++) {
    if (i % 2 == 1) {
      continue;
    }

    if (isdigit(expression[i])) {
      stack.push(expression[i] - '0');
      continue;
    }

    if (stack.size() < 2) {
      throw std::runtime_error("Error: Invalid expression");
    }

    long long result = 0;
    long long num1 = stack.top();
    stack.pop();
    long long num2 = stack.top();
    stack.pop();
    switch (expression[i]) {
    case '+':
      result = num2 + num1;
      break;
    case '-':
      result = num2 - num1;
      break;
    case '*':
      result = num2 * num1;
      break;
    case '/':
      if (num1 == 0) {
        throw std::runtime_error("Error: Division by zero");
      }
      result = num2 / num1;
      break;
    default:
      throw std::runtime_error("Error: Invalid expression");
    }
    if (result < INT_MIN || result > INT_MAX) {
      throw std::runtime_error("Error: Out of range");
    }
    stack.push(result);
  }
  if (stack.size() != 1) {
    throw std::runtime_error("Error: Invalid expression");
  }
  return stack.top();
}
