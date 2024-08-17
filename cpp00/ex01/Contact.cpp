#include "Contact.hpp"
#include <iostream>

int Contact::set_field(std::string *field)
{
	std::string str;
	if (!std::getline(std::cin, str))
		std::cout << std::endl;
	if (str.empty())
		return -1;
	*field = str;
	return 0;
}
