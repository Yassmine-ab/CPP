#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

void testInternBasics()
{
	std::cout << "\n========== INTERN BASICS TESTS ==========" << std::endl;

	std::cout << "\n--- Creating and destroying interns ---" << std::endl;
	Intern intern1;
	Intern intern2(intern1);
	Intern intern3;
	intern3 = intern1;
}

void testInternMakeFormValid()
{
	std::cout << "\n========== VALID FORM CREATION TESTS ==========" << std::endl;
	
	Intern intern;
	Bureaucrat boss("TheBoss", 1);
	
	std::cout << "\n--- Creating Shrubbery Creation Form ---" << std::endl;
	try
	{
		AForm* form1 = intern.makeForm("shrubbery creation", "home");
		std::cout << *form1 << std::endl;
		boss.signForm(*form1);
		boss.executeForm(*form1);
		delete form1;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Creating Robotomy Request Form ---" << std::endl;
	try
	{
		AForm* form2 = intern.makeForm("robotomy request", "Bender");
		std::cout << *form2 << std::endl;
		boss.signForm(*form2);
		boss.executeForm(*form2);
		delete form2;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
	try
	{
		AForm* form3 = intern.makeForm("presidential pardon", "Arthur Dent");
		std::cout << *form3 << std::endl;
		boss.signForm(*form3);
		boss.executeForm(*form3);
		delete form3;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testInternMakeFormInvalid()
{
	std::cout << "\n========== INVALID FORM CREATION TESTS ==========" << std::endl;
	
	Intern intern;

	std::cout << "\n--- Trying to create unknown form types ---" << std::endl;
	
	std::string invalidNames[5] = {
		"coffee making",
		"vacation request",
		"Shrubbery Creation",
		"ROBOTOMY REQUEST",
		""
	};
	
	for (int i = 0; i < 5; i++)
	{
		try
		{
			std::cout << "\nAttempting: \"" << invalidNames[i] << "\"" << std::endl;
			AForm* form = intern.makeForm(invalidNames[i], "target");
			std::cout << "Form created: " << *form << std::endl;
			delete form;
		}
		catch (std::exception& e)
		{
			std::cout << "Caught exception: " << e.what() << std::endl;
		}
	}
}

void testInternWorkflow()
{
	std::cout << "\n========== COMPLETE WORKFLOW TEST ==========" << std::endl;
	
	try
	{
		Intern intern;
		Bureaucrat midLevel("MidLevel", 50);
		Bureaucrat highLevel("HighLevel", 5);

		std::cout << "\n--- Workflow: Create, Sign, Execute ---" << std::endl;
		AForm* form = intern.makeForm("robotomy request", "Employee42");
		
		if (form)
		{
			std::cout << "\nForm details: " << *form << std::endl;
			
			// midLevel tente de signer 
			std::cout << "\n--- Mid level bureaucrat attempts to sign ---" << std::endl;
			midLevel.signForm(*form);
			
			// highLevel signe
			std::cout << "\n--- High level bureaucrat signs ---" << std::endl;
			highLevel.signForm(*form);
			
			// midLevel tente d'exécuter
			std::cout << "\n--- Mid level bureaucrat attempts to execute ---" << std::endl;
			midLevel.executeForm(*form);
			
			// highLevel exécute
			std::cout << "\n--- High level bureaucrat executes ---" << std::endl;
			highLevel.executeForm(*form);
			
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception in workflow: " << e.what() << std::endl;
	}
}

void testInternMultipleForms()
{
	std::cout << "\n========== MULTIPLE FORMS TEST ==========" << std::endl;
	
	try
	{
		Intern intern;
		Bureaucrat ceo("CEO", 1);
		
		std::cout << "\n--- Creating and processing multiple forms ---" << std::endl;

		AForm* forms[6];
		forms[0] = intern.makeForm("shrubbery creation", "garden1");
		forms[1] = intern.makeForm("shrubbery creation", "garden2");
		forms[2] = intern.makeForm("robotomy request", "target1");
		forms[3] = intern.makeForm("robotomy request", "target2");
		forms[4] = intern.makeForm("presidential pardon", "criminal1");
		forms[5] = intern.makeForm("presidential pardon", "criminal2");

		std::cout << "\n--- Processing all forms ---" << std::endl;
		for (int i = 0; i < 6; i++)
		{
			std::cout << "\n=== Form " << (i + 1) << " ===" << std::endl;
			if (forms[i])
			{
				ceo.signForm(*forms[i]);
				ceo.executeForm(*forms[i]);
			}
		}

		std::cout << "\n--- Cleaning up ---" << std::endl;
		for (int i = 0; i < 6; i++)
		{
			delete forms[i];
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void testSubjectExample()
{
	std::cout << "\n========== SUBJECT EXAMPLE TEST ==========" << std::endl;
	
	std::cout << "\n--- Running exact example from subject ---" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		if (rrf)
		{
			std::cout << "\nForm created successfully!" << std::endl;
			std::cout << *rrf << std::endl;

			Bureaucrat boss("Boss", 1);
			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			
			delete rrf;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main()
{
	testInternBasics();
	testInternMakeFormValid();
	testInternMakeFormInvalid();
	testInternWorkflow();
	testInternMultipleForms();
	testSubjectExample();

	return (0);
}
