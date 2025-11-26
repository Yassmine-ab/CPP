#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "--- ClapTrap Tests ---" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.attack("Bandit");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << "ClapTrap stats - HP: " << clap.getHitPoints() 
			  << ", Energy: " << clap.getEnergyPoints() 
			  << ", Damage: " << clap.getAttackDamage() << std::endl << std::endl;
	std::cout << "--- ScavTrap Construction Chaining ---" << std::endl;
	ScavTrap scav1("SC4V-TP");
	std::cout << "ScavTrap stats - HP: " << scav1.getHitPoints() 
			  << ", Energy: " << scav1.getEnergyPoints() 
			  << ", Damage: " << scav1.getAttackDamage() << std::endl;
	scav1.attack("Psycho");
	scav1.guardGate();
	std::cout << std::endl; 
	std::cout << "--- FragTrap Construction Chaining ---" << std::endl;
	FragTrap frag1("FR4G-TP");
	std::cout << "FragTrap stats - HP: " << frag1.getHitPoints() 
			  << ", Energy: " << frag1.getEnergyPoints() 
			  << ", Damage: " << frag1.getAttackDamage() << std::endl << std::endl;
	std::cout << "--- FragTrap Default Constructor ---" << std::endl;
	FragTrap frag2;
	std::cout << std::endl;
	std::cout << "--- FragTrap Copy Constructor ---" << std::endl;
	FragTrap frag3(frag1);
	std::cout << std::endl;
	std::cout << "--- FragTrap Assignment Operator ---" << std::endl;
	FragTrap frag4("TEMP");
	frag4 = frag1;
	std::cout << std::endl;
	std::cout << "--- FragTrap Functionality Tests ---" << std::endl;
	frag1.attack("Skag");
	frag1.attack("Spiderant");
	frag1.takeDamage(25);
	frag1.beRepaired(10);
	frag1.highFivesGuys();
	frag2.highFivesGuys();
	std::cout << std::endl;
	std::cout << "--- FragTrap Energy Test ---" << std::endl;
	FragTrap energyFrag("EnergyFrag");
	std::cout << "Starting energy: " << energyFrag.getEnergyPoints() << std::endl;
	for (int i = 0; i < 15; i++)
		energyFrag.attack("Target");
	std::cout << "Remaining energy: " << energyFrag.getEnergyPoints() << std::endl;
	energyFrag.highFivesGuys();
	std::cout << std::endl;
	std::cout << "--- FragTrap Destruction Test ---" << std::endl;
	FragTrap toughFrag("ToughFrag");
	std::cout << "Initial HP: " << toughFrag.getHitPoints() << std::endl;
	toughFrag.takeDamage(120);
	toughFrag.attack("Enemy");
	toughFrag.beRepaired(10);
	toughFrag.highFivesGuys();
	std::cout << std::endl;
	std::cout << "--- Mixed Robots Test ---" << std::endl;
	ClapTrap mixClap("MixClap");
	ScavTrap mixScav("MixScav");
	FragTrap mixFrag("MixFrag");
	std::cout << "\nComparing stats:" << std::endl;
	std::cout << "ClapTrap - HP:" << mixClap.getHitPoints() << " Energy:" << mixClap.getEnergyPoints() << " Damage:" << mixClap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap - HP:" << mixScav.getHitPoints() << " Energy:" << mixScav.getEnergyPoints() << " Damage:" << mixScav.getAttackDamage() << std::endl;
	std::cout << "FragTrap - HP:" << mixFrag.getHitPoints() << " Energy:" << mixFrag.getEnergyPoints() << " Damage:" << mixFrag.getAttackDamage() << std::endl;
	std::cout << "\nSpecial abilities:" << std::endl;
	mixScav.guardGate();
	mixFrag.highFivesGuys();
	std::cout << std::endl;
	return (0);
}