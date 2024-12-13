#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
public:
	Contact(std::string firstname, std::string lastname,
			std::string nickname, std::string phonenumber,
			std::string secret);
	Contact();
	std::string firstname_;
	std::string lastname_;
	std::string nickname_;

	bool is_legal();
	bool is_empty();

private:
	std::string phonenumber_;
	std::string secret_;
	bool is_empty_;
};

#endif
