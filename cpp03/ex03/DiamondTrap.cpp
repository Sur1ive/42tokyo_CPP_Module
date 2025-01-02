#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), name_(name) {
  std::cout << "DiamondTrap constructor called" << std::endl;
  FragTrap::hitPoints_ = 100;
  ScavTrap::energyPoints_ = 50;
  FragTrap::attackDamage_ = 30;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
  ClapTrap::operator=(other);
  name_ = other.name_;
  return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
  std::cout << "DiamondTrap copy constructor called" << std::endl;
  name_ = other.name_;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI() const {
  std::cout << "DiamondTrap name: " << name_ << "; ClapTrap name: " << ClapTrap::name_ << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}
