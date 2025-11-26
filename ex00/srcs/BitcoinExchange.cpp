#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->_database = other._database;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::trim(std::string& str) const
{
	size_t start = 0;

	while (start < str.length() && std::isspace(str[start]))
		start++;
	
	size_t end = str.length();
	while (end > start && std::isspace(str[end - 1]))
		end--;
	
	str = str.substr(start, end - start);
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int BitcoinExchange::getDaysInMonth(int month, int year) const
{
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if (month == 2 && isLeapYear(year))
		return (29);
	return (daysInMonth[month - 1]);
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
	// Format: YYYY-MM-DD
	if (date.length() != 10)
		return (false);
	
	if (date[4] != '-' || date[7] != '-')
		return (false);
	
	// Check si tous les autres caractères sont des chiffres
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i != 4 && i != 7 && std::isdigit(date[i]) == false)
			return (false);
	}
	
	// Extrait l'année, le mois, le jour
	int year = std::atoi(date.substr(0, 4).c_str()); // c_str() convertit std::string en const char*
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	
	// Valide les plages
	if (year < 2009 || year > 2025)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > getDaysInMonth(month, year))
		return (false);
	
	return (true);
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
	if (valueStr.empty())
		return (false);
	
	char* end;
	value = std::strtof(valueStr.c_str(), &end);
	
	// Check si la conversion a réussi
	if (*end != '\0' && *end != '\n')
		return (false);
	
	return (true);
}

std::string BitcoinExchange::findClosestDate(const std::string& date) const
{
	// Trouve la première date dans la base de données qui n'est pas antérieure à la date donnée
	std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
	
	// Si la date exacte existe
	if (it != _database.end() && it->first == date)
		return (it->first);
	
	// Si il n'y a pas de date antérieure
	if (it == _database.begin())
		return ("");
	
	// Retourne la date antérieure la plus proche
	--it;
	return (it->first);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (file.is_open() == false)
	{
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line))
	{
		// Saute la ligne "date,exchange_rate"
		if (firstLine == true)
		{
			firstLine = false;
			continue;
		}
		
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		
		std::string date = line.substr(0, commaPos);
		std::string valueStr = line.substr(commaPos + 1);
		
		trim(date);
		trim(valueStr);
		
		if (isValidDate(date))
		{
			float value;
			if (isValidValue(valueStr, value))
				_database[date] = value;
		}
	}
	
	file.close();
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (file.is_open() == false)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	
	std::string line;
	bool firstLine = true;
	
	while (std::getline(file, line))
	{
		if (firstLine == true)
		{
			firstLine = false;
			continue;
		}
		
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);
		
		trim(date);
		trim(valueStr);

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		float value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		std::string closestDate = findClosestDate(date);
		if (closestDate.empty())
		{
			std::cerr << "Error: no valid date in database before " << date << std::endl;
			continue;
		}

		float exchangeRate = _database[closestDate];
		float result = value * exchangeRate;
		
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	
	file.close();
}
