#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() : _contactCount(0), _nextIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

std::string	PhoneBook::readUserInput(const std::string &prompt) const
{
	std::string	input;
	
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
		if (!input.empty())
			break;
		std::cout << "This field cannot be empty. Please try again." << std::endl;
	}
	return (input);
}

void	PhoneBook::addContact()
{
	Contact	newContact;
	
	std::cout << std::endl << "Adding a new contact:" << std::endl;
	std::cout << "---------------------" << std::endl;
	newContact.setFirstName(readUserInput("First Name: "));
	newContact.setLastName(readUserInput("Last Name: "));
	newContact.setNickname(readUserInput("Nickname: "));
	newContact.setPhoneNumber(readUserInput("Phone Number: "));
	newContact.setDarkestSecret(readUserInput("Darkest Secret: "));
	_contacts[_nextIndex] = newContact;
	_nextIndex = (_nextIndex + 1) % MAX_CONTACTS;
	if (_contactCount < MAX_CONTACTS)
		_contactCount++;
	std::cout << std::endl << "Contact added successfully!" << std::endl;
}

void	PhoneBook::displayContactsTable() const
{
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	
	for (int i = 0; i < _contactCount; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << _contacts[i].truncateString(_contacts[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << _contacts[i].truncateString(_contacts[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << _contacts[i].truncateString(_contacts[i].getNickname(), 10) << std::endl;
	}
	std::cout << std::endl;
}

bool	PhoneBook::isValidIndex(const std::string &input, int &index) const
{
	if (input.length() != 1 || !std::isdigit(input[0]))
		return (false);
	
	index = input[0] - '0';
	return (index >= 0 && index < _contactCount);
}

void	PhoneBook::searchContacts() const
{
	std::string	input;
	int	index;

	if (_contactCount == 0)
	{
		std::cout << std::endl << "No contacts available. Add some contacts first!" << std::endl;
		return;
	}
	displayContactsTable();
	while (true)
	{
		std::cout << "Enter the index of the contact to display: ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			return;
		}
		if (isValidIndex(input, index))
		{
			std::cout << std::endl << "Contact details:" << std::endl;
			std::cout << "----------------" << std::endl;
			_contacts[index].showContactDetails();
			break;
		}
		else
			std::cout << "Invalid index. Please enter a number between 0 and " << (_contactCount - 1) << "." << std::endl;
	}
}

void	PhoneBook::displayMenu() const
{
	std::cout << std::endl;
	std::cout << "WELCOME TO MY PHONEBOOK!" << std::endl;
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
	std::cout << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "  • ADD    - Add a new contact" << std::endl;
	std::cout << "  • SEARCH - Search and display contacts" << std::endl;
	std::cout << "  • EXIT   - Exit the program" << std::endl;
	std::cout << std::endl;
}
