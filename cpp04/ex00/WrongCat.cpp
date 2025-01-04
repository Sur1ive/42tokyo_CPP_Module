#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
  std::cout << "WrongCat constructor called" << std::endl;
  type_ = "WrongCat";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  WrongAnimal::operator=(other);
  return *this;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}
