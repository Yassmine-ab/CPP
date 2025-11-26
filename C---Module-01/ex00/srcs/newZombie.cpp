#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}

/*
L'opérateur new alloue de la mémoire dynamiquement sur le heap
et retourne un pointeur vers l'objet créé.
Il est impératif d'utiliser delete pour libérer cette mémoire
lorsque l'objet n'est plus nécessaire, afin d'éviter les fuites de mémoire.
La fonction newZombie doit retourner un pointeur vers un zombie qui survit hors du scope de la fonction.
Si on créait le zombie sur la stack, le zombie serait détruit à la fin de la fonction, rendant le pointeur invalide.
*/