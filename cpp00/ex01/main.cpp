#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

int main(void)
{
	PhoneBook phonebook;
	std::string cmd;
	std::cout << "Welcome to your awesome phonebook app!" << std::endl;
	std::cout << "Enter \"ADD\" to add a new contact" << std::endl;
	std::cout << "Enter \"SEARCH\" to search a contact" << std::endl;
	std::cout << "Enter \"EXIT\" to exit" << std::endl;
	while (true)
	{
		std::cout << "phonebook> ";
		if (!std::getline(std::cin, cmd))
			exit(0);

		if (cmd == "EXIT")
			exit(0);
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
	}
}
