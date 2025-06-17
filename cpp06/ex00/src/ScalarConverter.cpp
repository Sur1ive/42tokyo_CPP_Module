#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>

static bool is_literal_legal(const std::string &literal) {
  if (literal.empty()) {
    return false;
  }

  if (literal.length() == 1) {
    return true;
  }

  if (literal == "nan" || literal == "nanf" || literal == "+inf" ||
      literal == "-inf" || literal == "+inff" || literal == "-inff") {
    return true;
  }

  int dot_count = 0;
  int digit_count = 0;
  for (size_t i = 0; i < literal.length(); i++) {
    if (!isdigit(literal[i])) {
      if (i == 0 && (literal[i] == '+' || literal[i] == '-')) {
        continue;
      }
      if (literal[i] == '.') {
        dot_count++;
        if (dot_count > 1 || i == 0 || i == literal.length() - 1 ||
            (literal[literal.length() - 1] == 'f' &&
             i == literal.length() - 2) ||
            (i == 1 && (literal[0] == '-' || literal[0] == '+'))) {
          return false;
        }
        continue;
      }
      if (i == literal.length() - 1 && literal[i] == 'f') {
        continue;
      }
      return false;
    }
    digit_count++;
  }
  if (digit_count == 0) {
    return false;
  }
  return true;
}

static void convert_illegal() {
  std::cout << "char: " << "impossible" << std::endl;
  std::cout << "int: " << "impossible" << std::endl;
  std::cout << "float: " << "impossible" << std::endl;
  std::cout << "double: " << "impossible" << std::endl;
}

static void convert_char(const char c) {
  int i = static_cast<int>(c);
  float f = static_cast<float>(c);
  double d = static_cast<double>(c);

  if (!isprint(c)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

static void convert_int(const int i) {
  char c = static_cast<char>(i);
  float f = static_cast<float>(i);
  double d = static_cast<double>(i);

  if (i < CHAR_MIN || i > CHAR_MAX) {
    std::cout << "char: " << "impossible" << std::endl;
  } else if (!isprint(c)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }
  std::cout << "int: " << i << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

static void convert_float(const float f) {
  char c = static_cast<char>(f);
  int i = static_cast<int>(f);
  double d = static_cast<double>(f);

  if (trunc(d) < static_cast<double>(CHAR_MIN) ||
      trunc(d) > static_cast<double>(CHAR_MAX) || std::isinf(f) ||
      std::isnan(f)) {
    std::cout << "char: " << "impossible" << std::endl;
  } else if (!isprint(c)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }

  if (trunc(d) < static_cast<double>(INT_MIN) ||
      trunc(d) > static_cast<double>(INT_MAX) || std::isinf(f) ||
      std::isnan(f)) {
    std::cout << "int: " << "impossible" << std::endl;
  } else {
    std::cout << "int: " << i << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

static void convert_double(const double d) {
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);
  float f = static_cast<float>(d);

  if (trunc(d) < static_cast<double>(CHAR_MIN) ||
      trunc(d) > static_cast<double>(CHAR_MAX) || std::isinf(d) ||
      std::isnan(d)) {
    std::cout << "char: " << "impossible" << std::endl;
  } else if (!isprint(c)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }
  if (trunc(d) < static_cast<double>(INT_MIN) ||
      trunc(d) > static_cast<double>(INT_MAX) || std::isinf(d) ||
      std::isnan(d)) {
    std::cout << "int: " << "impossible" << std::endl;
  } else {
    std::cout << "int: " << i << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

void ScalarConverter::convert(const std::string &literal) {
  if (!is_literal_legal(literal)) {
    convert_illegal();
    return;
  }

  if (literal.length() == 1 && !isdigit(literal[0])) {
    convert_char(literal[0]);
    return;
  }

  if (literal == "nan" || literal == "+inf" || literal == "-inf") {
    convert_double(std::strtod(literal.c_str(), NULL));
    return;
  }

  if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
    convert_float(std::atof(literal.c_str()));
    return;
  }

  if (literal[literal.length() - 1] == 'f') {
    convert_float(std::atof(literal.c_str()));
    return;
  }

  if (literal.find('.') != std::string::npos) {
    convert_double(std::strtod(literal.c_str(), NULL));
    return;
  }

  if (std::strtod(literal.c_str(), NULL) < INT_MIN ||
      std::strtod(literal.c_str(), NULL) > INT_MAX) {
    convert_illegal();
    return;
  }
  convert_int(std::atoi(literal.c_str()));
}
