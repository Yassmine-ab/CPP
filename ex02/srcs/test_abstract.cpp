/*
Ce main démontre que la classe Animal est maintenant abstraite.
Si on décommente les lignes ci-dessous, la compilation échouera :

#include "Animal.hpp"

int main() {
    // ❌ ERREUR DE COMPILATION !
    // Animal animal;              // "cannot declare variable 'animal' to be of abstract type 'Animal'"
    // Animal* ptr = new Animal(); // "invalid new-expression of abstract class type 'Animal'"
    
    return (0);
}

*/