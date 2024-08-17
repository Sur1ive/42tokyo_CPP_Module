#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	int set_field(std::string *field);

	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenumber;
	std::string secret;
};

#endif
