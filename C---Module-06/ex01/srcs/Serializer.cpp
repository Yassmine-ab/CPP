#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other)
{
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
	(void)other;
	return (*this);
}

Serializer::~Serializer()
{
}

// convertit un pointeur vers Data en un entier non signé uintptr_t
// uintptr_t garantit qu'un pointeur peut être stocké sans perte d'information
// reinterpret_cast réinterprète les bits bruts d'un type vers un autre type
uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
