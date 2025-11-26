#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cerrno>
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

static int detectType(const std::string& literal)
{
	// 0: char, 1: int, 2: float, 3: double
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (0);
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		return (2);
	if (literal == "nan" || literal == "+inf" || literal == "-inf")
		return (3);
	if (literal[literal.length() - 1] == 'f' && literal.length() > 1)
	{
		std::string temp = literal.substr(0, literal.length() - 1);
		size_t dotCount = 0;
		for (size_t i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '.')
				dotCount++;
		}
		if (dotCount == 1)
			return (2);
	}
	size_t dotCount = 0;
	for (size_t i = 0; i < literal.length(); i++)
	{
		if (literal[i] == '.')
			dotCount++;
	}
	if (dotCount == 1)
		return (3);
	return (1);
}

static bool isCharPrintable(char c)
{
	return (c >= ' ' && c <= '~');
}

static void convertFromChar(char c)
{
	// char
	std::cout << "char: ";
	if (isCharPrintable(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	
	// int
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	
	// float
	std::cout << "float: " << std::fixed << std::setprecision(1) 
			  << static_cast<float>(c) << "f" << std::endl;
	
	// double
	std::cout << "double: " << std::fixed << std::setprecision(1) 
			  << static_cast<double>(c) << std::endl;
}

static void convertFromInt(int n)
{
	// char
	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "impossible" << std::endl;
	else if (!isCharPrintable(static_cast<char>(n)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
	
	// int
	std::cout << "int: " << n << std::endl;
	
	// float
	std::cout << "float: " << std::fixed << std::setprecision(1) 
			  << static_cast<float>(n) << "f" << std::endl;
	
	// double
	std::cout << "double: " << std::fixed << std::setprecision(1) 
			  << static_cast<double>(n) << std::endl;
}

static void convertFromFloat(float f)
{
	// char
	std::cout << "char: ";
	if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (!isCharPrintable(static_cast<char>(f)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	
	// int
	std::cout << "int: ";
	if (std::isnan(f) || std::isinf(f) || f < INT_MIN || f > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	
	// float
	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(f))
	{
		if (f > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	
	// double
	std::cout << "double: ";
	if (std::isnan(f))
		std::cout << "nan" << std::endl;
	else if (std::isinf(f))
	{
		if (f > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) 
				  << static_cast<double>(f) << std::endl;
}

static void convertFromDouble(double d)
{
	// char
	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (!isCharPrintable(static_cast<char>(d)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	
	// int
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	
	// float
	std::cout << "float: ";
	if (std::isnan(d))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(d))
	{
		if (d > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) 
				  << static_cast<float>(d) << "f" << std::endl;
	
	// double
	std::cout << "double: ";
	if (std::isnan(d))
		std::cout << "nan" << std::endl;
	else if (std::isinf(d))
	{
		if (d > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
		std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
	int type = detectType(literal);
	
	switch (type)
	{
		case 0: // char
		{
			char c = literal[1];
			convertFromChar(c);
			break;
		}
		case 1: // int
		{
			errno = 0;
			char* endptr;
			long n = std::strtol(literal.c_str(), &endptr, 10); // Peut mettre errno à ERANGE en cas d'overflow/underflow
			// c_str convertit std::string en const char* car strtol attend un const char*
			// strtol convertit la chaîne en long
			if (errno == ERANGE || n < INT_MIN || n > INT_MAX || *endptr != '\0')
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			convertFromInt(static_cast<int>(n));
			break;
		}
		case 2: // float
		{
			errno = 0;
			char* endptr;
			float f = std::strtof(literal.c_str(), &endptr);
			
			if (errno == ERANGE && !std::isinf(f))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			convertFromFloat(f);
			break;
		}
		case 3: // double
		{
			errno = 0;
			char* endptr;
			double d = std::strtod(literal.c_str(), &endptr);
			
			if (errno == ERANGE && !std::isinf(d))
			{
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: impossible" << std::endl;
				return;
			}
			convertFromDouble(d);
			break;
		}
	}
}
