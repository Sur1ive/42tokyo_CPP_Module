#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
  std::cout << "Brain constructor called" << std::endl;
  for (int i = 0; i < 100; i++)
    ideas_[i] = "";
}

Brain& Brain::operator=(const Brain& other) {
  for (int i = 0; i < 100; i++)
    ideas_[i] = other.ideas_[i];
  return *this;
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain copy constructor called" << std::endl;
  *this = other;
}

Brain::~Brain() {
  std::cout << "Brain destructor called" << std::endl;
}
