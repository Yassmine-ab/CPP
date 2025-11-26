#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	this->_fixedPointValue = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::~Fixed(void)
{
}

Fixed::Fixed(const int value)
{
	this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value)
{
	this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits));
}

int Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

int Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->_fixedPointValue != other._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result._fixedPointValue = (this->_fixedPointValue * other._fixedPointValue) >> this->_fractionalBits;
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	result._fixedPointValue = (this->_fixedPointValue << this->_fractionalBits) / other._fixedPointValue;
	return (result);
}

Fixed& Fixed::operator++(void)
{
	++this->_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	temp(*this);

	++this->_fixedPointValue;
	return (temp);
}

Fixed& Fixed::operator--(void)
{
	--this->_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	temp(*this);

	--this->_fixedPointValue;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return ((a < b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return ((a > b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}