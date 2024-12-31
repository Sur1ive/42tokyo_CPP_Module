#include "Fixed.hpp"
#include <iostream>
#include <cmath>

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
  os << obj.toFloat();
  return os;
}

Fixed::Fixed() : value_(0) {}

Fixed::Fixed(const Fixed& other) {
  *this = other;
}

Fixed::Fixed(const int num) {
  value_ = num << numberOfFractionalBits_;
}

Fixed::Fixed(const float num) {
  value_ = roundf(num * (1 << numberOfFractionalBits_));
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
  value_ = other.getRawBits();
  return *this;
}

bool Fixed::operator>(const Fixed& other) const {
  return value_ > other.getRawBits();
}

bool Fixed::operator<(const Fixed& other) const {
  return value_ < other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const {
  return value_ >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const {
  return value_ <= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const {
  return value_ == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const {
  return value_ != other.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
  ++value_;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed cp = *this;
  ++(*this);
  return cp;
}

Fixed& Fixed::operator--() {
  --value_;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed cp = *this;
  --(*this);
  return cp;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
  return (f1 >= f2) ? f1 : f2;
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2) {
  return (f1 >= f2) ? f1 : f2;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
  return (f1 <= f2) ? f1 : f2;
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2) {
  return (f1 <= f2) ? f1 : f2;
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
