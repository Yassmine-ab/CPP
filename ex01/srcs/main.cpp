#include "Zombie.hpp"

int	main(void)
{
	int	hordeSize = 5;
	std::string	zombieName = "ZombieHorde";
	std::cout << "-> Creating a horde of " << hordeSize << " zombies" << std::endl;
	Zombie*	horde = zombieHorde(hordeSize, zombieName);
	if (horde == NULL)
	{
		std::cout << "Failed to create zombie horde!" << std::endl;
		return (1);
	}
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie " << i + 1 << ": ";
		horde[i].announce();
	}
	std::cout << std::endl;
	std::cout << "-> Destroying the horde" << std::endl;
	delete[] (horde);
	return (0);
}