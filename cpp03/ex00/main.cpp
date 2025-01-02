#include "ClapTrap.hpp"

int main() {
  ClapTrap a;
  ClapTrap b("test");
  ClapTrap c(b);

  a.attack("111");

  a = c;

  a.attack("111");
  b.takeDamage(100);
  b.beRepaired(100);
  b.attack("222");
  c.beRepaired(100);
  c.attack("222");

  return 0;
}
