#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  type_ = other.type_;
  return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
  *this = other;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "?" << std::endl;
}

std::string WrongAnimal::getType() const {
  return type_;
}
