#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called" << std::endl;
  hitPoints_ = 100;
  energyPoints_ = 100;
  attackDamage_ = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
  ClapTrap::operator=(other);
  return *this;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
  std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys() const {
  std::cout << "High fives guys!" << std::endl;
}

void FragTrap::attack(const std::string& target) {
  if (hitPoints_ <= 0) {
    std::cout << "FragTrap " << name_ << " tries to attack but"
              << " has no hit points left" << std::endl;
    return;
  }
  if (energyPoints_ <= 0) {
    std::cout << "FragTrap " << name_ << " tries to attack but"
              << " has no energy points left" << std::endl;
    return;
  }

  std::cout << "FragTrap " << name_ << " attacks " << target
            << ", causing " << attackDamage_ << " points of damage!" << std::endl;
  energyPoints_--;
}


