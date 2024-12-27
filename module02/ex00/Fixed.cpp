#include "Fixed.hpp"

Fixed::Fixed() : fixedNumber(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &new_object)
{
	fixedNumber = new_object.fixedNumber;
	std::cout << "Copy constructor called\n"; 
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called\n";

	if (this != &other)
	{
		fixedNumber = other.fixedNumber;
	}

	return (*this);
}