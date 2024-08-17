#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	{
		this->contact_num = 0;
		for (int i = 0; i < 9; i++)
			this->contacts[i] = 0;
	}
}

void PhoneBook::add_contact(Contact contact)
{
	if (this->contact_num >= 8)
	{
		contacts[this->contact_num++ % 8] = &contact;
		std::cout << "Contact has been added successfully\
			and the oldest one has been deleted." << std::endl;
	}
	else
	{
		contacts[this->contact_num++] = &contact;
		std::cout << "Contact has been added successfully." << std::endl;
	}
}

void PhoneBook::add()
{
	Contact contact;
	int flag = 0;
	std::cout << "Please enter first name: ";
	flag += contact.set_field(&contact.firstname);
	std::cout << "Please enter last name: ";
	flag += contact.set_field(&contact.firstname);
	std::cout << "Please enter nickname: ";
	flag += contact.set_field(&contact.firstname);
	std::cout << "Please enter phone number: ";
	flag += contact.set_field(&contact.firstname);
	std::cout << "Please enter darkest secret: ";
	flag += contact.set_field(&contact.firstname);
	if (flag == 0)
		this->add_contact(contact);
	else
		std::cout << "A contact can't have empty fields" << std::endl;
}
