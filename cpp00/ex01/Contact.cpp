#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact(std::string firstname, std::string lastname,
			std::string nickname, std::string phonenumber,
			std::string secret)
		: _firstname(firstname), _lastname(lastname), _nickname(nickname),
		  _phonenumber(phonenumber), _secret(secret), _is_empty(false) {}

Contact::Contact() : _is_empty(true) {}

bool Contact::is_legal()
{
	return (_firstname.empty() || _lastname.empty() ||
		_nickname.empty() || _phonenumber.empty() ||
		_secret.empty()) ? false : true;
}

bool Contact::is_empty()
{
	return (_is_empty);
}
