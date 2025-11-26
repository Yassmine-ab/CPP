#include "Base.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	std::cout << "\n--- Testing with randomly generated objects ---" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << "\nTest " << (i + 1) << ":" << std::endl;
		Base* instance = generate();
		
		std::cout << "Identified via pointer:   ";
		identify(instance);
		
		std::cout << "Identified via reference: ";
		identify(*instance);
		
		delete instance;
	}
	return (0);
}
