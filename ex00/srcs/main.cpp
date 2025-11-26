#include "Bureaucrat.hpp"
#include <iostream>

void testValidBureaucrat()
{
	std::cout << "\n=== Testing valid bureaucrat creation ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
		
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		
		Bureaucrat charlie("Charlie", 150);
		std::cout << charlie << std::endl;
	}
	catch (std::exception& e) 
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidBureaucrat()
{
	std::cout << "\n=== Testing invalid bureaucrat creation ===" << std::endl;

	try
	{
		Bureaucrat invalidHigh("TooHigh", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat invalidLow("TooLow", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeIncrement()
{
	std::cout << "\n=== Testing grade increment ===" << std::endl;
	try
	{
		Bureaucrat dave("Dave", 3);
		std::cout << "Before increment: " << dave << std::endl;
		
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;

		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testGradeDecrement()
{
	std::cout << "\n=== Testing grade decrement ===" << std::endl;
	try
	{
		Bureaucrat eve("Eve", 148);
		std::cout << "Before decrement: " << eve << std::endl;
		
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
		
		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;

		eve.decrementGrade();
		std::cout << "After decrement: " << eve << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testCopyAndAssignment()
{
	std::cout << "\n=== Testing copy constructor and assignment ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 50);
		std::cout << "Original: " << original << std::endl;

		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;

		Bureaucrat assigned("Assigned", 100);
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	testValidBureaucrat();
	testInvalidBureaucrat();
	testGradeIncrement();
	testGradeDecrement();
	testCopyAndAssignment();

	return (0);
}