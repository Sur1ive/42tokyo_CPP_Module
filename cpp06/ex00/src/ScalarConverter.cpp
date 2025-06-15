#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
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

static void convert_float(const float f, const bool int_overflow) {
  char c = static_cast<char>(f);
  int i = static_cast<int>(f);
  double d = static_cast<double>(f);

  if (i < 0 || i > 127 || std::isinf(f) || std::isnan(f)) {
    std::cout << "char: " << "impossible" << std::endl;
  } else if (!isprint(i)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }

  if (int_overflow) {
    std::cout << "int: " << "impossible" << std::endl;
  } else {
    std::cout << "int: " << i << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

static void convert_double(const double d, const bool int_overflow) {
  char c = static_cast<char>(d);
  int i = static_cast<int>(d);
  float f = static_cast<float>(d);

  if (i < 0 || i > 127 || std::isinf(d) || std::isnan(d)) {
    std::cout << "char: " << "impossible" << std::endl;
  } else if (!isprint(i)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }
  if (int_overflow) {
    std::cout << "int: " << "impossible" << std::endl;
  } else {
    std::cout << "int: " << i << std::endl;
  }
  std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
            << std::endl;
  std::cout << "double: " << std::fixed << std::setprecision(1) << d
            << std::endl;
}

static void convert_int(const int i, const bool int_overflow) {
  char c = static_cast<char>(i);
  float f = static_cast<float>(i);
  double d = static_cast<double>(i);

  if (i < 0 || i > 127 || std::isinf(d) || std::isnan(d)) {
    std::cout << "char: " << "Non displayable" << std::endl;
  } else {
    std::cout << "char: '" << c << "'" << std::endl;
  }
  if (int_overflow) {
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
    convert_double(std::strtod(literal.c_str(), NULL), true);
    return;
  }

  if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
    convert_float(std::atof(literal.c_str()), true);
    return;
  }

  bool int_overflow = false;
  errno = 0;
  (void)std::atoi(literal.c_str());
  if (errno == ERANGE) {
    int_overflow = true;
  }

  if (literal[literal.length() - 1] == 'f') {
    convert_float(std::atof(literal.c_str()), int_overflow);
    return;
  }

  if (literal.find('.') != std::string::npos) {
    convert_double(std::strtod(literal.c_str(), NULL), int_overflow);
    return;
  }

  convert_int(std::atoi(literal.c_str()), int_overflow);
  return;
}
