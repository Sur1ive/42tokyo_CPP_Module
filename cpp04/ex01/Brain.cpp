#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << "Brain constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
  ideas_ = other.ideas_;
  return *this;
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = other;
}

Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}
