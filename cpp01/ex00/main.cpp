#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie* zombie = newZombie("aaa");
	zombie->announce();
	randomChump("bbb");
	delete zombie;
	return 0;
}
