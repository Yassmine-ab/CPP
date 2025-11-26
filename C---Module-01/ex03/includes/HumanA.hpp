#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/* -------------------------------------------------------------------------- */
/*                                HUMANA CLASS                                */
/* -------------------------------------------------------------------------- */

class HumanA
{
	private:
	std::string _name;
	Weapon& _weapon; 

	public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	
	void attack() const;
};

#endif

/*
HumanA est TOUJOURS armé dès sa création
L'arme est obligatoire au constructeur
Une fois créé, HumanA ne peut jamais être désarmé
La référence garantit qu'il y a toujours une arme valide
*/