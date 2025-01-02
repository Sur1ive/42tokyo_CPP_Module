#include "ScavTrap.hpp"

int main() {
  // ClapTrap a("test");
  // ClapTrap b;
  // ClapTrap c(b);

  // a.attack("111");

  // a = c;

  // a.attack("111");
  // b.takeDamage(100);
  // b.beRepaired(100);
  // b.attack("222");
  // c.beRepaired(100);
  // c.attack("222");


  ScavTrap aa;
  ScavTrap bb("test");
  ScavTrap cc(bb);

  aa.attack("111");

  aa = cc;

  aa.attack("111");
  bb.takeDamage(100);
  bb.beRepaired(100);
  bb.attack("222");
  cc.beRepaired(100);
  cc.attack("222");

  return 0;
}
