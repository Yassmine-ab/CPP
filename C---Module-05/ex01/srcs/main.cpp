#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void testFormCreation()
{
	std::cout << "\n=== Testing Form creation ===" << std::endl;
	try
	{
		Form taxForm("Tax Form", 50, 25);
		std::cout << taxForm << std::endl;
		
		Form importantForm("Important Form", 1, 1);
		std::cout << importantForm << std::endl;
		
		Form easyForm("Easy Form", 150, 150);
		std::cout << easyForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidFormCreation()
{
	std::cout << "\n=== Testing invalid Form creation ===" << std::endl;
	try
	{
		Form invalidHigh("Invalid High", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Form invalidLow("Invalid Low", 50, 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testSuccessfulSigning()
{
	std::cout << "\n=== Testing successful form signing ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 25);
		Form taxForm("Tax Form", 50, 25);
		
		std::cout << "Before signing: " << taxForm << std::endl;
		alice.signForm(taxForm);
		std::cout << "After signing: " << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testFailedSigning()
{
	std::cout << "\n=== Testing failed form signing ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 100);
		Form importantForm("Important Form", 50, 25);
		
		std::cout << "Before signing attempt: " << importantForm << std::endl;
		bob.signForm(importantForm);
		std::cout << "After signing attempt: " << importantForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testDirectBeSigned()
{
	std::cout << "\n=== Testing direct beSigned method ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 10);
		Form testForm("Test Form", 15, 10);
		
		std::cout << "Before beSigned: " << testForm << std::endl;
		testForm.beSigned(charlie);
		std::cout << "After beSigned: " << testForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat dave("Dave", 100);
		Form restrictedForm("Restricted Form", 50, 25);
		
		std::cout << "Before beSigned: " << restrictedForm << std::endl;
		restrictedForm.beSigned(dave);
		std::cout << "After beSigned: " << restrictedForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testFormCopyAndAssignment()
{
	std::cout << "\n=== Testing Form copy and assignment ===" << std::endl;
	try
	{
		Form original("Original Form", 75, 50);
		Bureaucrat signer("Signer", 50);

		signer.signForm(original);
		std::cout << "Original: " << original << std::endl;

		Form copy(original);
		std::cout << "Copy: " << copy << std::endl;

		Form assigned("Assigned Form", 100, 75);
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
	testFormCreation();
	testInvalidFormCreation();
	testSuccessfulSigning();
	testFailedSigning();
	testDirectBeSigned();
	testFormCopyAndAssignment();
	
	return (0);
}