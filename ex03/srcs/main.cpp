#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	std::cout << "--- ClapTrap Tests ---" << std::endl;
	ClapTrap clap("CL4P-TP");
	clap.attack("Bandit");
	std::cout << "ClapTrap stats - HP: " << clap.getHitPoints() 
			  << ", Energy: " << clap.getEnergyPoints() 
			  << ", Damage: " << clap.getAttackDamage() << std::endl << std::endl;
	std::cout << "--- ScavTrap Tests ---" << std::endl;
	ScavTrap scav("SC4V-TP");
	scav.attack("Psycho");
	scav.guardGate();
	std::cout << "ScavTrap stats - HP: " << scav.getHitPoints() 
			  << ", Energy: " << scav.getEnergyPoints() 
			  << ", Damage: " << scav.getAttackDamage() << std::endl << std::endl;
	std::cout << "--- FragTrap Tests ---" << std::endl;
	FragTrap frag("FR4G-TP");
	frag.attack("Skag");
	frag.highFivesGuys();
	std::cout << "FragTrap stats - HP: " << frag.getHitPoints() 
			  << ", Energy: " << frag.getEnergyPoints() 
			  << ", Damage: " << frag.getAttackDamage() << std::endl << std::endl;
	std::cout << "--- DiamondTrap Construction Chaining ---" << std::endl;
	DiamondTrap diamond1("DI4M-TP");
	std::cout << "DiamondTrap stats - HP: " << diamond1.getHitPoints() 
			  << ", Energy: " << diamond1.getEnergyPoints() 
			  << ", Damage: " << diamond1.getAttackDamage() << std::endl;
	std::cout << "DiamondTrap name: " << diamond1.getName() << std::endl;
	std::cout << "DiamondTrap ClapTrap name: " << diamond1.getClapTrapName() << std::endl << std::endl;
	std::cout << "--- DiamondTrap Default Constructor ---" << std::endl;
	DiamondTrap diamond2;
	std::cout << "Default DiamondTrap name: " << diamond2.getName() << std::endl;
	std::cout << "Default DiamondTrap ClapTrap name: " << diamond2.getClapTrapName() << std::endl << std::endl;
	std::cout << "--- DiamondTrap Copy Constructor ---" << std::endl;
	DiamondTrap diamond3(diamond1);
	std::cout << "Copied DiamondTrap name: " << diamond3.getName() << std::endl;
	std::cout << "Copied DiamondTrap ClapTrap name: " << diamond3.getClapTrapName() << std::endl << std::endl;
	std::cout << "--- DiamondTrap Assignment Operator ---" << std::endl;
	DiamondTrap diamond4("TEMP");
	diamond4 = diamond1;
	std::cout << "Assigned DiamondTrap name: " << diamond4.getName() << std::endl;
	std::cout << "Assigned DiamondTrap ClapTrap name: " << diamond4.getClapTrapName() << std::endl << std::endl;
	std::cout << "--- DiamondTrap Functionality Tests ---" << std::endl;
	diamond1.attack("Rakk");
	diamond1.attack("Varkid");
	diamond1.guardGate();
	diamond1.highFivesGuys();
	diamond1.whoAmI();
	diamond2.whoAmI();
	std::cout << std::endl;
	std::cout << "--- DiamondTrap Attributes Verification ---" << std::endl;
	std::cout << "DiamondTrap should have:" << std::endl;
	std::cout << "- Hit Points from FragTrap (100): " << diamond1.getHitPoints() << std::endl;
	std::cout << "- Energy Points from ScavTrap (50): " << diamond1.getEnergyPoints() << std::endl;
	std::cout << "- Attack Damage from FragTrap (30): " << diamond1.getAttackDamage() << std::endl;
	std::cout << "- Attack method from ScavTrap (should say 'ScavTrap' in messages)" << std::endl << std::endl;
	std::cout << "--- DiamondTrap Damage and Repair Tests ---" << std::endl;
	diamond1.takeDamage(25);
	diamond1.beRepaired(10);
	std::cout << "After damage and repair - HP: " << diamond1.getHitPoints() 
			  << ", Energy: " << diamond1.getEnergyPoints() << std::endl << std::endl;
	std::cout << "--- DiamondTrap Energy Test ---" << std::endl;
	DiamondTrap energyDiamond("EnergyDiamond");
	std::cout << "Starting energy: " << energyDiamond.getEnergyPoints() << std::endl;
	for (int i = 0; i < 10; i++)
		energyDiamond.attack("Target");
	std::cout << "Remaining energy: " << energyDiamond.getEnergyPoints() << std::endl;
	energyDiamond.guardGate();
	energyDiamond.highFivesGuys();
	energyDiamond.whoAmI();
	std::cout << std::endl;
	std::cout << "--- DiamondTrap Destruction Test ---" << std::endl;
	DiamondTrap destructDiamond("DestructDiamond");
	destructDiamond.takeDamage(150);
	destructDiamond.attack("Enemy");
	destructDiamond.beRepaired(10);
	destructDiamond.guardGate();
	destructDiamond.highFivesGuys();
	destructDiamond.whoAmI();
	std::cout << std::endl;
	std::cout << "--- All Robot Types Comparison ---" << std::endl;
	ClapTrap mixClap("MixClap");
	ScavTrap mixScav("MixScav");
	FragTrap mixFrag("MixFrag");
	DiamondTrap mixDiamond("MixDiamond");
	std::cout << "\nComparing stats:" << std::endl;
	std::cout << "ClapTrap  - HP:" << mixClap.getHitPoints() << " Energy:" << mixClap.getEnergyPoints() << " Damage:" << mixClap.getAttackDamage() << std::endl;
	std::cout << "ScavTrap  - HP:" << mixScav.getHitPoints() << " Energy:" << mixScav.getEnergyPoints() << " Damage:" << mixScav.getAttackDamage() << std::endl;
	std::cout << "FragTrap  - HP:" << mixFrag.getHitPoints() << " Energy:" << mixFrag.getEnergyPoints() << " Damage:" << mixFrag.getAttackDamage() << std::endl;
	std::cout << "DiamondTrap - HP:" << mixDiamond.getHitPoints() << " Energy:" << mixDiamond.getEnergyPoints() << " Damage:" << mixDiamond.getAttackDamage() << std::endl;
	std::cout << "\nSpecial abilities:" << std::endl;
	mixScav.guardGate();
	mixFrag.highFivesGuys();
	mixDiamond.guardGate();
	mixDiamond.highFivesGuys();
	mixDiamond.whoAmI();
	std::cout << std::endl;
	return (0);
}