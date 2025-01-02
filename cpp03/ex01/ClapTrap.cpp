#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(const std::string& name): name_(name), hitPoints_(10),
  energyPoints_(10), attackDamage_(0) {
  std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
  name_ = other.name_;
  hitPoints_ = other.hitPoints_;
  energyPoints_ = other.energyPoints_;
  attackDamage_ = other.attackDamage_;
  return *this;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = other;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
  if (hitPoints_ <= 0) {
    std::cout << "ClapTrap " << name_ << " tries to attack but"
              << " has no hit points left" << std::endl;
    return;
  }
  if (energyPoints_ <= 0) {
    std::cout << "ClapTrap " << name_ << " tries to attack but"
              << " has no energy points left" << std::endl;
    return;
  }

  std::cout << "ClapTrap " << name_ << " attacks " << target
            << ", causing " << attackDamage_ << " points of damage!" << std::endl;
  energyPoints_--;
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << name_ << " takes " << amount
            << " points of damage!" << std::endl;
  hitPoints_ -= amount;
  if (hitPoints_ == 0)
    hitPoints_ = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (hitPoints_ <= 0) {
    std::cout << name_ << " tries to repair itself but"
              << " has no hit points left" << std::endl;
    return;
  }
  if (energyPoints_ <= 0) {
    std::cout << name_ << " tries to repair itself but"
              << " has no energy points left" << std::endl;
    return;
  }

  std::cout << name_ << " is repaired, recovers " << amount
            << " hit points!" << std::endl;
  energyPoints_--;
  hitPoints_ += amount;
}
