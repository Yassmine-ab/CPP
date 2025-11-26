#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete (heapZombie);
	std::cout << std::endl;
	randomChump("StackZombie");
	std::cout << std::endl;
	return (0);
}