#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {
public:
  ClapTrap(const std::string& name = "default");
  ClapTrap(const ClapTrap& other);
  virtual ~ClapTrap();
  ClapTrap& operator=(const ClapTrap& other);

  virtual void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

protected:
  std::string name_;
  unsigned int hitPoints_;
  unsigned int energyPoints_;
  int attackDamage_;
};

#endif
