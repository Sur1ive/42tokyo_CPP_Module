#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	void rename(std::string name);

private:
	std::string name;
};

#endif
