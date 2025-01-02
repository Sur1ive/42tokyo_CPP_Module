#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap(const std::string& name = "default");
  DiamondTrap(const DiamondTrap& other);
  ~DiamondTrap();
  DiamondTrap& operator=(const DiamondTrap& other);

  void whoAmI() const;
  virtual void attack(const std::string& target); // override
private:
  std::string name_;
};

#endif
