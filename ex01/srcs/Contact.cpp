#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(const std::string &firstName)
{
	_firstName = firstName;
}

void	Contact::setLastName(const std::string &lastName)
{
	_lastName = lastName;
}

void	Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void	Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string	Contact::getNickname() const
{
	return (_nickname);
}

std::string	Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

bool	Contact::isEmpty() const
{
	return (_firstName.empty() && _lastName.empty() && _nickname.empty() 
		   && _phoneNumber.empty() && _darkestSecret.empty());
}

void	Contact::showContactDetails() const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

std::string	Contact::truncateString(const std::string &str, size_t width) const
{
	if (str.length() > width)
		return (str.substr(0, width - 1) + ".");
	return (str);
}
