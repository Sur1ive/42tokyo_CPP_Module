#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
public:
	HumanA();

	void attack();

private:
	std::string name;
	Weapon weapon;
};

#endif
