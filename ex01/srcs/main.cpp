#include "Span.hpp"
#include <iostream>

int main(void)
{
	// Test du sujet
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	// Tests aditionnels
	std::cout << "\nTesting exceptions:" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	Span empty = Span(10);
	try
	{
		std::cout << empty.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	// Test avec 100 000 nombres
	std::cout << "\nTesting with 10,000 numbers using addRange:" << std::endl;
	Span bigSpan = Span(10000);
	std::vector<int> numbers;
	
	for (int i = 0; i < 10000; ++i)
	{
		numbers.push_back(i);
	}
	
	bigSpan.addRange(numbers.begin(), numbers.end());
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	
	return (0);
}

