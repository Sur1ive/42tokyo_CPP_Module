#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(const std::string& name = "default");
  FragTrap(const FragTrap& other);
  ~FragTrap();
  FragTrap& operator=(const FragTrap& other);

  void highFivesGuys() const;
  virtual void attack(const std::string& target); // override
};

#endif
