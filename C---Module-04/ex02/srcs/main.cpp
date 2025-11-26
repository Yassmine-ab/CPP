
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void arrayTests()
{
	const int arraySize = 6;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}
	for (int i = 0; i < arraySize; i++)
		delete animals[i];
}

void deepCopyTests()
{
	Dog original;
	{
		Dog copy = original;
		std::cout << "Copy created and going out of scope..." << std::endl;
	}
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
}

void extraTests()
{
	Dog d1;
	Dog d2 = d1;
	Cat c1;
	Cat c2;
	c2 = c1;
	d1.makeSound();
	c1.makeSound();
}

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;
	arrayTests();
	deepCopyTests();
	extraTests();
	return (0);
}