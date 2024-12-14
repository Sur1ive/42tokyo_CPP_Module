#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
public:
	PhoneBook();

	void search();
	void add();

private:
	Contact contacts_[8];
	int		contact_count_;

	void add_contact(Contact* contact);
	void show_contacts();
};

#endif
