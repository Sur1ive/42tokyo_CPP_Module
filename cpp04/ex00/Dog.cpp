#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
  std::cout << "Dog constructor called" << std::endl;
  type_ = "Dog";
}

Dog& Dog::operator=(const Dog& other) {
  Animal::operator=(other);
  return *this;
}

Dog::Dog(const Dog& other) : Animal(other) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = other;
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
  std::cout << "Woof!" << std::endl;
}
