#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "--- Constructor Tests ---" << std::endl;
	ClapTrap robot1("R2D2");
	ClapTrap robot2("C3PO");
	ClapTrap robot3;
	std::cout << std::endl;
	std::cout << "--- Copy Constructor Test ---" << std::endl;
	ClapTrap robot4(robot1);
	std::cout << std::endl;
	std::cout << "--- Assignment Operator Test ---" << std::endl;
	ClapTrap robot5("BB8");
	robot5 = robot2;
	std::cout << std::endl;
	std::cout << "--- Attack Tests ---" << std::endl;
	robot1.attack("Enemy");
	robot1.attack("Another Enemy");
	std::cout << "R2D2 energy points: " << robot1.getEnergyPoints() << std::endl << std::endl;
	std::cout << "--- Damage Tests ---" << std::endl;
	robot2.takeDamage(3);
	std::cout << "C3PO hit points: " << robot2.getHitPoints() << std::endl;
	robot2.takeDamage(5);
	std::cout << "C3PO hit points: " << robot2.getHitPoints() << std::endl;
	robot2.takeDamage(10);
	std::cout << "C3PO hit points: " << robot2.getHitPoints() << std::endl;
	robot2.takeDamage(1);
	std::cout << std::endl;
	std::cout << "--- Repair Tests ---" << std::endl;
	robot1.beRepaired(5);
	std::cout << "R2D2 hit points: " << robot1.getHitPoints() << std::endl;
	std::cout << "R2D2 energy points: " << robot1.getEnergyPoints() << std::endl;
	robot1.beRepaired(3);
	std::cout << "R2D2 hit points: " << robot1.getHitPoints() << std::endl;
	std::cout << "R2D2 energy points: " << robot1.getEnergyPoints() << std::endl << std::endl;
	std::cout << "--- Energy Depletion Tests ---" << std::endl;
	ClapTrap energyTest("EnergyBot");
	std::cout << "Starting energy: " << energyTest.getEnergyPoints() << std::endl;
	for (int i = 0; i < 8; i++) {
		energyTest.attack("Target");
	}
	std::cout << "Remaining energy: " << energyTest.getEnergyPoints() << std::endl;
	energyTest.attack("Target");
	energyTest.beRepaired(1);
	std::cout << std::endl;
	std::cout << "--- Repair Destroyed Robot Test ---" << std::endl;
	robot2.beRepaired(5);
	std::cout << std::endl;
	return (0);
}