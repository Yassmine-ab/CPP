#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

/* -------------------------------------------------------------------------- */
/*                                HUMANB CLASS                                */
/* -------------------------------------------------------------------------- */

class HumanB
{
	private:
	std::string _name;
	Weapon* _weapon;

	public:
	HumanB(const std::string& name);
	~HumanB();
	
	void setWeapon(Weapon& weapon);
	void attack() const;
};

#endif

/*
HumanB peut être désarmé (créé sans arme)
L'arme peut être définie plus tard avec setWeapon()
Le pointeur peut être null → État "désarmé" possible
Plus de flexibilité dans l'utilisation
*/