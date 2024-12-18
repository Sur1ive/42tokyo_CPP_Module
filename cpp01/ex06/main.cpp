#include "Harl.hpp"
#include <iostream>

int getLevel(std::string level)
{
    if (level == "debug") return 0;
    if (level == "info") return 1;
    if (level == "warning") return 2;
    if (level == "error") return 3;
	return -1;
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "wrong arguement number" << std::endl;
		return 1;
	}

	Harl harl;

	switch (getLevel(argv[1]))
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("debug");
		std::cout << std::endl;
		/* fall through */
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("info");
		std::cout << std::endl;
		/* fall through */
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("warning");
		std::cout << std::endl;
		/* fall through */
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("error");
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
	return 0;
}
