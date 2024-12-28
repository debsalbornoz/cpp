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

bool    Fixed::operator>(const Fixed &new_object) const
{
    return (fixedNumber > new_object.fixedNumber);
}

bool    Fixed::operator<(const Fixed &new_object) const
{
    return (fixedNumber < new_object.fixedNumber);
}

bool    Fixed::operator>=(const Fixed &new_object) const
{
    return (fixedNumber >= new_object.fixedNumber);
}

bool    Fixed::operator<=(const Fixed &new_object) const
{
    return (fixedNumber <= new_object.fixedNumber);
}

bool    Fixed::operator==(const Fixed &new_object) const
{
    return (fixedNumber == new_object.fixedNumber);
}

bool    Fixed::operator!=(const Fixed &new_object) const
{
    return (fixedNumber != new_object.fixedNumber);
}

Fixed   Fixed::operator+(const Fixed &new_object) const
{
    Fixed result;

    result.fixedNumber = (fixedNumber + new_object.fixedNumber) >> Fixed::fractions;
    return (result);
}

Fixed   Fixed::operator-(const Fixed &new_object) const
{
    Fixed result;

    result.fixedNumber = (fixedNumber - new_object.fixedNumber) >> Fixed::fractions;
    return (result);
}

Fixed Fixed::operator*(const Fixed &new_object) const
{
    Fixed result;
    result.fixedNumber = (fixedNumber * new_object.fixedNumber) >> Fixed::fractions;
    return result;
}


Fixed   Fixed::operator/(const Fixed &new_object) const
{
    Fixed result;

    result.fixedNumber = (fixedNumber / new_object.fixedNumber) >> Fixed::fractions;
    return (result);
}

Fixed& Fixed::operator++(void)
{
    fixedNumber++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    fixedNumber++;
    return (tmp);
}

Fixed& Fixed::operator--(void)
{
    fixedNumber--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    fixedNumber--;
    return (tmp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}
