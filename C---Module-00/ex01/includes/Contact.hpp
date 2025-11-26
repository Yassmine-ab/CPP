#ifndef CONTACT_HPP
#define CONTACT_HPP

/* -------------------------------------------------------------------------- */
/*                                  INCLUDES                                  */
/* -------------------------------------------------------------------------- */

#include <string>
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                                   CLASS                                    */
/* -------------------------------------------------------------------------- */

class Contact
{
	private:
	// Attributs
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	public:
	// Constructeur/Destructeur
	Contact();
	~Contact();

	// Getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	// Setters
	void		setFirstName(const std::string &firstName);
	void		setLastName(const std::string &lastName);
	void		setNickname(const std::string &nickname);
	void		setPhoneNumber(const std::string &phoneNumber);
	void		setDarkestSecret(const std::string &darkestSecret);

	// Autres méthodes
	bool		isEmpty() const;
	void		showContactDetails() const;
	std::string	truncateString(const std::string &str, size_t width) const;
};

#endif
