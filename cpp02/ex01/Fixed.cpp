#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  value_ = other.getRawBits();
}

Fixed::Fixed(const int num) {
  value_ = num << numberOfFractionalBits_;
}

Fixed::Fixed(const float num) {

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
  std::cout << "getRawBits member function called" << std::endl;
  return value_;
}

void Fixed::setRawBits(int const raw) {
  value_ = raw;
  std::cout << "setRawBits member function called" << std::endl;
}

float Fixed::toFloat(void) const {

}

int Fixed::toInt(void) const {
  
}
