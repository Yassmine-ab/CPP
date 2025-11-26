#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap clap("CL4P-TP");
	clap.attack("Bandit");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << "ClapTrap stats - HP: " << clap.getHitPoints() 
			  << ", Energy: " << clap.getEnergyPoints() 
			  << ", Damage: " << clap.getAttackDamage() << std::endl << std::endl;
	std::cout << "--- ScavTrap Construction Chaining ---" << std::endl;
	ScavTrap scav1("SC4V-TP");
	std::cout << std::endl;
	std::cout << "--- ScavTrap Default Constructor ---" << std::endl;
	ScavTrap scav2;
	std::cout << std::endl;
	std::cout << "--- ScavTrap Copy Constructor ---" << std::endl;
	ScavTrap scav3(scav1);
	std::cout << std::endl;
	std::cout << "--- ScavTrap Assignment Operator ---" << std::endl;
	ScavTrap scav4("TEMP");
	scav4 = scav1;
	std::cout << std::endl;
	std::cout << "--- ScavTrap Functionality Tests ---" << std::endl;
	std::cout << "ScavTrap stats - HP: " << scav1.getHitPoints() 
			  << ", Energy: " << scav1.getEnergyPoints() 
			  << ", Damage: " << scav1.getAttackDamage() << std::endl;

	scav1.attack("Psycho");
	scav1.attack("Goliath");
	scav1.takeDamage(30);
	scav1.beRepaired(15);
	scav1.guardGate();
	scav2.guardGate();
	std::cout << std::endl;
	std::cout << "--- ScavTrap Energy Test ---" << std::endl;
	ScavTrap energyTest("EnergyTester");
	std::cout << "Starting energy: " << energyTest.getEnergyPoints() << std::endl;
	for (int i = 0; i < 10; i++)
		energyTest.attack("Target");
	std::cout << "Remaining energy: " << energyTest.getEnergyPoints() << std::endl;
	energyTest.guardGate();
	std::cout << std::endl;
	std::cout << "--- ScavTrap Destruction Test ---" << std::endl;
	ScavTrap toughBot("ToughBot");
	std::cout << "Initial HP: " << toughBot.getHitPoints() << std::endl;
	toughBot.takeDamage(150);
	toughBot.attack("Enemy");
	toughBot.beRepaired(10);
	toughBot.guardGate();
	std::cout << std::endl;
	return (0);
}

/*
ScavTrap dépend de ClapTrap pour exister
On ne peut pas détruire ClapTrap tant que ScavTrap l'utilise encore
car il essaierait d'utiliser de la mémoire invalide
*/