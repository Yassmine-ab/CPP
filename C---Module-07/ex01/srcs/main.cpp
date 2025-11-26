#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T& element)
{
	std::cout << element << " ";
}

template <typename T>
void increment(T& element)
{
	element++;
}

int main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = 5;
	
	std::cout << "Int array: ";
	iter(intArray, intSize, print<int>);
	std::cout << std::endl;
	
	iter(intArray, intSize, increment<int>);
	std::cout << "After increment: ";
	iter(intArray, intSize, print<int>);
	std::cout << std::endl;

	std::string stringArray[] = {"Hello", "World", "C++"};
	size_t stringSize = 3;
	
	std::cout << "String array: ";
	iter(stringArray, stringSize, print<std::string>);
	std::cout << std::endl;
	
	return (0);
}
