#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void testShrubberyCreationForm()
{
	std::cout << "\n========== SHRUBBERY CREATION FORM TESTS ==========" << std::endl;
	
	try
	{
		// Crée des bureaucrats avec différents grades
		Bureaucrat lowGrade("LowGrade", 150);
		Bureaucrat midGrade("MidGrade", 140);
		Bureaucrat highGrade("HighGrade", 130);
		
		// Crée un formulaire
		ShrubberyCreationForm shrubForm("garden");
		std::cout << shrubForm << std::endl;

		// Teste la signature avec un grade insuffisant
		std::cout << "\n--- Testing signing with insufficient grade ---" << std::endl;
		lowGrade.signForm(shrubForm);

		// Teste la signature avec un grade suffisant
		std::cout << "\n--- Testing signing with sufficient grade ---" << std::endl;
		midGrade.signForm(shrubForm);
		
		// Teste l'exécution avec un grade suffisant
		std::cout << "\n--- Testing execution with sufficient grade ---" << std::endl;
		highGrade.executeForm(shrubForm);

		// Teste l'exécution avec un grade insuffisant sur un formulaire non signé
		ShrubberyCreationForm unsignedForm("park");
		std::cout << "\n--- Testing execution on unsigned form ---" << std::endl;
		highGrade.executeForm(unsignedForm);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testRobotomyRequestForm()
{
	std::cout << "\n========== ROBOTOMY REQUEST FORM TESTS ==========" << std::endl;
	try
	{
		// Crée des bureaucrats avec différents grades
		Bureaucrat lowGrade("TechAssistant", 80);
		Bureaucrat midGrade("Engineer", 70);
		Bureaucrat highGrade("ChiefEngineer", 40);
		
		// Crée un formulaire
		RobotomyRequestForm robotForm("Alice");
		std::cout << robotForm << std::endl;

		// Teste la signature avec un grade insuffisant
		std::cout << "\n--- Testing signing with insufficient grade ---" << std::endl;
		lowGrade.signForm(robotForm);

		// Teste la signature avec un grade suffisant
		std::cout << "\n--- Testing signing with sufficient grade ---" << std::endl;
		midGrade.signForm(robotForm);

		// Teste l'exécution (plusieurs tentatives pour voir les résultats aléatoires)
		std::cout << "\n--- Testing execution (multiple attempts for randomness) ---" << std::endl;
		for (int i = 0; i < 3; i++)
		{
			std::cout << "\nAttempt " << (i + 1) << ":" << std::endl;
			highGrade.executeForm(robotForm);
		}
		
		// Teste l'exécution avec un grade insuffisant
		RobotomyRequestForm robotForm2("Bob");
		midGrade.signForm(robotForm2);
		std::cout << "\n--- Testing execution with insufficient grade ---" << std::endl;
		lowGrade.executeForm(robotForm2);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testPresidentialPardonForm()
{
	std::cout << "\n========== PRESIDENTIAL PARDON FORM TESTS ==========" << std::endl;
	try
	{
		// Crée des bureaucrats avec différents grades
		Bureaucrat lowGrade("Secretary", 30);
		Bureaucrat midGrade("Minister", 20);
		Bureaucrat highGrade("President", 1);
		
		// Crée un formulaire
		PresidentialPardonForm pardonForm("Charlie");
		std::cout << pardonForm << std::endl;
		
		// Teste la signature avec un grade insuffisant
		std::cout << "\n--- Testing signing with insufficient grade ---" << std::endl;
		lowGrade.signForm(pardonForm);

		// Teste la signature avec un grade suffisant
		std::cout << "\n--- Testing signing with sufficient grade ---" << std::endl;
		midGrade.signForm(pardonForm);
		
		// Teste l'exécution avec un grade suffisant
		std::cout << "\n--- Testing execution with sufficient grade ---" << std::endl;
		highGrade.executeForm(pardonForm);
		
		// Teste l'exécution avec un grade insuffisant
		std::cout << "\n--- Testing execution with insufficient grade ---" << std::endl;
		midGrade.executeForm(pardonForm);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testPolymorphism()
{
	std::cout << "\n========== POLYMORPHISM TESTS ==========" << std::endl;
	try
	{
		Bureaucrat boss("BigBoss", 1);
		
		// Crée différents types de formulaires via des pointeurs de la classe de base
		AForm* forms[3];
		forms[0] = new ShrubberyCreationForm("office");
		forms[1] = new RobotomyRequestForm("employee1");
		forms[2] = new PresidentialPardonForm("employee2");
		
		// Signe et exécute chaque formulaire
		for (int i = 0; i < 3; i++)
		{
			std::cout << "\n--- Processing form " << (i + 1) << " ---" << std::endl;
			std::cout << *forms[i] << std::endl;
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]);
		}
		
		// Clean up
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int main()
{
	testShrubberyCreationForm();
	testRobotomyRequestForm();
	testPresidentialPardonForm();
	testPolymorphism();

	return (0);
}
