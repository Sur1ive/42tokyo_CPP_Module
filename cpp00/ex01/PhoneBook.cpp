#include "PhoneBook.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook()
{
	contact_count_ = 0;
	for (int i = 0; i < 8; i++)
		contacts_[i] = Contact();
}

void PhoneBook::add_contact(Contact *contact)
{
	contacts_[contact_count_++ % 8] = *contact;
	if (contact_count_ >= 8)
	{
		contact_count_ = 8 + contact_count_ % 8;
		std::cout << "Added successfully and the oldest one has been deleted." << std::endl;
	}
	else
		std::cout << "Contact has been added successfully." << std::endl;
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
		add_contact(&contact);
	else
		std::cout << "A contact can't have empty fields" << std::endl;
}

void PhoneBook::show_contacts()
{
	std::cout << std::setw(10) << "index" << " | ";
	std::cout << std::setw(10) << "first name" << " | ";
	std::cout << std::setw(10) << "last name" << " | ";
	std::cout << std::setw(10) << "nickname" << std::endl;
	int i = 0;
	while (i < 8 && !contacts_[i].is_empty())
	{
		std::cout << std::setw(10) << i + 1 << " | ";
		std::cout << std::setw(10) << contacts_[i].firstname_ << " | ";
		std::cout << std::setw(10) << contacts_[i].lastname_ << " | ";
		std::cout << std::setw(10) << contacts_[i].nickname_ << std::endl;
		i++;
	}
}

void PhoneBook::search()
{
	show_contacts();
}

std::string PhoneBook::get_input(std::string prompt)
{
	std::cout << prompt;
	std::string str;
	if (!std::getline(std::cin, str))
		exit(0);
	return str;
}
