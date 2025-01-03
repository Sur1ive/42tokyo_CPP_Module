#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
  std::cout << "WrongCat constructor called" << std::endl;
  type_ = "WrongCat";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  type_ = other.type_;
  return *this;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal() {
  std::cout << "WrongCat copy constructor called" << std::endl;
  *this = other;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}
