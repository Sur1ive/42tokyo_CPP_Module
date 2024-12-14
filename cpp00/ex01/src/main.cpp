#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
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
		std::getline(std::cin, cmd);
		if (std::cin.eof() || cmd == "EXIT")
			return (0);
		try
		{
			if (cmd == "ADD")
				phonebook.add();
			if (cmd == "SEARCH")
				phonebook.search();
		}
		catch (std::runtime_error& e)
		{
			return (0);
		}
	}
}
