#include "PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	phoneBook.displayMenu();
	while (true)
	{
		std::cout << "Enter one command> ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl << "Goodbye!" << std::endl;
			break;
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContacts();
		else if (command == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else if (!command.empty())
		{
			std::cout << "Unknown command: '" << command << "'" << std::endl;
			std::cout << "Please use ADD, SEARCH, or EXIT." << std::endl;
		}
	}
	return (0);
}
