#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
  os << obj.toFloat();
  return os;
}

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::Fixed(const int num) {
  std::cout << "Int constructor called" << std::endl;
  value_ = num << numberOfFractionalBits_;
}

Fixed::Fixed(const float num) {
  std::cout << "Float constructor called" << std::endl;
  value_ = roundf(num * (1 << numberOfFractionalBits_));
}

Fixed& Fixed::operator=(const Fixed& other) {
  std::cout << "Copy assignment operator called" << std::endl;
  value_ = other.getRawBits();
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  return value_;
}

void Fixed::setRawBits(int const raw) {
  value_ = raw;
}

float Fixed::toFloat(void) const {
  return (float)value_ / (1 << numberOfFractionalBits_);
}

int Fixed::toInt(void) const {
  return value_ >> numberOfFractionalBits_;
}
