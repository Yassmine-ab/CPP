#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

int	Fixed::getRawBits(void) const
{
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

/*
L'opérateur de décalage binaire (<<) ne fonctionne qu'avec des entiers.
L'opérateur d'insertion (<<) est utilisé pour insérer des données dans un flux de sortie (comme std::cout).
C'est un opérateur global, pas un membre de la classe.
std::ostream est la classe de base pour tous les flux de sortie.
Les flux ne peuvent pas être copiés, d'où la nécessité de la référence.
Le return (os); est essentiel pour permettre le chaînage des opérateurs <<.
*/