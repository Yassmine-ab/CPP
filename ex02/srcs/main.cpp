#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> empty;
	std::cout << "Empty array size: " << empty.size() << std::endl;

	Array<int> numbers(5);
	std::cout << "Numbers array size: " << numbers.size() << std::endl;

	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i;
	
	std::cout << "Numbers: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl;

	Array<int> copy = numbers;
	copy[0] = 42;
	
	std::cout << "Original: " << numbers[0] << std::endl;
	std::cout << "Copy: " << copy[0] << std::endl;

	try
	{
		std::cout << numbers[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught" << std::endl;
	}
	
	return (0);
}