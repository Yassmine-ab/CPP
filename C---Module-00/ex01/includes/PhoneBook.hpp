#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

/* -------------------------------------------------------------------------- */
/*                                  INCLUDES                                  */
/* -------------------------------------------------------------------------- */

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

/* -------------------------------------------------------------------------- */
/*                                   CLASS                                    */
/* -------------------------------------------------------------------------- */

class PhoneBook
{
	private:
	// Attributs
	static const int	MAX_CONTACTS = 8;
	Contact				_contacts[MAX_CONTACTS];
	int					_contactCount;
	int					_nextIndex;

	// Méthodes privées
	std::string	readUserInput(const std::string &prompt) const;
	bool		isValidIndex(const std::string &input, int &index) const;
	void		displayContactsTable() const;

	public:
	// Constructeur/Destructeur
	PhoneBook();
	~PhoneBook();

	// Autres méthodes
	void addContact();
	void searchContacts() const;
	void displayMenu() const;
};

#endif
