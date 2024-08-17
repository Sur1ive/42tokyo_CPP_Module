#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	void add_contact(Contact contact);
public:
	PhoneBook();

	void search();
	void add(void);

	Contact *contacts[9];
	int		contact_num;
};

#endif
