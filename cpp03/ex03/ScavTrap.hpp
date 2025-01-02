#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(const std::string& name = "default");
  ScavTrap(const ScavTrap& other);
  ~ScavTrap();
  ScavTrap& operator=(const ScavTrap& other);

  void guardGate() const;
  virtual void attack(const std::string& target); // override
};

#endif
