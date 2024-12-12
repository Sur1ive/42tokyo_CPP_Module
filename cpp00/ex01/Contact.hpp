#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phonenumber;
	std::string _secret;

public:
	Contact(std::string firstname, std::string lastname,
			std::string nickname, std::string phonenumber,
			std::string secret);

	bool is_legal();
};

#endif
