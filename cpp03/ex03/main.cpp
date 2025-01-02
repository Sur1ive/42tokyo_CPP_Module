#include "DiamondTrap.hpp"

int main() {
  DiamondTrap aa;
  DiamondTrap bb("test");
  DiamondTrap cc(bb);

  aa.attack("111");
  aa.whoAmI();
  aa.guardGate();
  aa.highFivesGuys();

  aa = cc;
  aa.whoAmI();
  bb.whoAmI();
  cc.whoAmI();

  aa.attack("111");
  bb.takeDamage(100);
  bb.beRepaired(100);
  bb.attack("222");
  cc.beRepaired(100);
  cc.attack("222");

  return 0;
}
