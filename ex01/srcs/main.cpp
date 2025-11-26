#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

int main()
{
	// Créer une structure Data
	Data data;
	data.id = 42;
	data.name = "Test";
	
	// Sérialiser
	uintptr_t serialized = Serializer::serialize(&data);
	
	// Désérialiser
	Data* deserialized = Serializer::deserialize(serialized);
	
	// Vérifier l'égalité
	if (deserialized == &data)
		std::cout << "Success: pointers are equal" << std::endl;
	else
		std::cout << "Error: pointers differ" << std::endl;
	
	return (0);
}
