#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <exception>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _database; // map pour stocker les données de la base de données
		
		bool		isValidDate(const std::string& date) const;
		bool		isValidValue(const std::string& valueStr, float& value) const;
		bool		isLeapYear(int year) const;
		int			getDaysInMonth(int month, int year) const;
		void		trim(std::string& str) const;
		std::string	findClosestDate(const std::string& date) const;
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		void		loadDatabase(const std::string& filename);
		void		processInputFile(const std::string& filename);
};

#endif
