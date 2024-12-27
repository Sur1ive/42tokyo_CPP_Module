#include "ClapTrap.hpp"

int main() {
  ClapTrap a;
  ClapTrap b("test");
  ClapTrap c(b);

  a = c;

  a.attack("111");
  b.takeDamage(100);
  b.beRepaired(100);
  c.beRepaired(100);

  return 0;
}
