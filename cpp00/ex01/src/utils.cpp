#include "utils.hpp"

std::string get_input(std::string prompt)
{
	std::cout << prompt;
	std::string str;
	std::getline(std::cin, str);
	if (std::cin.eof())
		throw std::runtime_error("reach EOF");
	return str;
}

std::string truncate_str(std::string str)
{
	return str.length() > 10 ? str.substr(0, 9) + '.' : str;
}
