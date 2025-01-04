#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type_ = "Dog";
  brain_ = new Brain;
}

Dog& Dog::operator=(const Dog& other) {
  if (this == &other)
    return *this;
  delete brain_;
  brain_ = new Brain(*other.brain_);
  type_ = other.type_;
  return *this;
}

Dog::Dog(const Dog& other) : Animal() {
  std::cout << "Dog copy constructor called" << std::endl;
  brain_ = NULL;
  *this = other;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain_;
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}
