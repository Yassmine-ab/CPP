#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(), _name("Default")
{
	_energyPoints = 50;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	_energyPoints = 50;
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

std::string DiamondTrap::getName(void) const
{
	return (_name);
}

std::string DiamondTrap::getClapTrapName(void) const
{
	return (ClapTrap::_name);
}