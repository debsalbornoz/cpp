#include "Fixed.hpp"

Fixed::Fixed() : fixedNumber(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int n) : fixedNumber(n << Fixed::fractions)
{
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float value) : fixedNumber(roundf(value * (1 << fractions)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &new_object) : fixedNumber(new_object.fixedNumber) {
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

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedNumber);
}

void Fixed::setRawBits( int const raw )
{
	
	fixedNumber = raw;
}

int Fixed::toInt( void ) const
{
    return (Fixed::fixedNumber >> Fixed::fractions);
}

float Fixed::toFloat( void ) const
{
    return ((float)Fixed::fixedNumber / (1 << Fixed::fractions));
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return (out);
}