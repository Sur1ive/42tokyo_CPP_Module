#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
  std::cout << "Animal constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  type_ = other.type_;
  return *this;
}

Animal::Animal(const Animal& other) {
  std::cout << "Animal copy constructor called" << std::endl;
  *this = other;
}

Animal::~Animal() {
  std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const {
    std::cout << "?" << std::endl;
}

std::string Animal::getType() const {
  return type_;
}
