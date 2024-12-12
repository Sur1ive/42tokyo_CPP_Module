#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_contact_count;

	std::string get_input(std::string prompt);
	void add_contact(Contact* contact);

public:
	PhoneBook();

	void search();
	void add();
};

#endif
