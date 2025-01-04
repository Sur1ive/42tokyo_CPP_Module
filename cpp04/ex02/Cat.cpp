#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
  std::cout << "Cat constructor called" << std::endl;
  type_ = "Cat";
  brain_ = new Brain;
}

Cat& Cat::operator=(const Cat& other) {
  if (this == &other)
    return *this;
  delete brain_;
  brain_ = new Brain(*other.brain_);
  type_ = other.type_;
  return *this;
}

Cat::Cat(const Cat& other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
  brain_ = NULL;
  *this = other;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain_;
}

void Cat::makeSound() const {
    std::cout << "Meow~" << std::endl;
}
