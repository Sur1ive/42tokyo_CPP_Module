#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(std::string firstname, std::string lastname,
			std::string nickname, std::string phonenumber,
			std::string secret)
		: firstname_(firstname), lastname_(lastname), nickname_(nickname),
		  phonenumber_(phonenumber), secret_(secret), is_empty_(false) {}

Contact::Contact() : is_empty_(true) {}

bool Contact::is_legal()
{
	return (firstname_.empty() || lastname_.empty() ||
		nickname_.empty() || phonenumber_.empty() ||
		secret_.empty()) ? false : true;
}

bool Contact::is_empty()
{
	return (is_empty_);
}
