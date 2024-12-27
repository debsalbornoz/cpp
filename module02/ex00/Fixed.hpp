#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					fixedNumber;
		static const int	fractions = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &new_object);
		Fixed &operator = (const Fixed &new_object);
		//int getRawBits( void ) const;
		//void setRawBits( int const raw );
};

#endif