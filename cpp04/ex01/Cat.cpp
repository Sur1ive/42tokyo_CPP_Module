#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type_ = "Cat";
}

Cat& Cat::operator=(const Cat& other) {
  type_ = other.type_;
  return *this;
}

Cat::Cat(const Cat& other) : Animal() {
  std::cout << "Cat copy constructor called" << std::endl;
  *this = other;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow~" << std::endl;
}
