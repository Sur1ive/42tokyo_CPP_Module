#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int main(void)
{
	PhoneBook phonebook;
	std::string cmd;
	std::cout << "Welcome to your awesome phonebook app!" << std::endl;
	std::cout << "Enter \"ADD\" to add a new contact" << std::endl;
	std::cout << "Enter \"SEARCH\" to search a contact" << std::endl;
	std::cout << "Enter \"EXIT\" to exit" << std::endl;
	while (1)
	{
		std::cout << "phonebook> ";
		if (!std::getline(std::cin, cmd))
			break;
		if (cmd == "EXIT")
			return 0;
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
		{

		}
	}
	return 0;
}
