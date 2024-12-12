#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

PhoneBook::PhoneBook()
{
	_contact_num = 0;
	for (int i = 0; i < 9; i++)
		_contacts[i] = NULL;
}

void PhoneBook::add_contact(Contact contact)
{
	if (_contact_num >= 8)
	{
		_contacts[_contact_num++ % 8] = &contact;
		std::cout << "Contact has been added successfully\
			and the oldest one has been deleted."
				  << std::endl;
	}
	else
	{
		_contacts[_contact_num++] = &contact;
		std::cout << "Contact has been added successfully." << std::endl;
	}
}

void PhoneBook::add()
{
	std::string firstname = get_input("Please enter first name: ");
	std::string lastname = get_input("Please enter last name: ");
	std::string nickname = get_input("Please enter nickname: ");
	std::string phonenumber = get_input("Please enter phone number: ");
	std::string secret = get_input("Please enter secret: ");
	Contact contact = Contact(firstname, lastname, nickname, phonenumber, secret);
	if (contact.is_legal())
		add_contact(contact);
	else
		std::cout << "A contact can't have empty fields" << std::endl;
}

void PhoneBook::search()
{

}

std::string PhoneBook::get_input(std::string prompt)
{
	std::cout << prompt;
	std::string str;
	if (!std::getline(std::cin, str))
		exit(0);
	return str;
}
