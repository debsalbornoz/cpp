#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					fixedNumber;
		static const int	fractions = 8;
	public:
		Fixed();
        Fixed(const int n);
        Fixed(const float n);
		~Fixed();
		Fixed(const Fixed &new_object);
		Fixed &operator = (const Fixed &new_object);
		int     getRawBits( void ) const;
		void    setRawBits( int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;
        bool    operator>(const Fixed &new_object) const;
        bool    operator<(const Fixed &new_object) const;
        bool    operator>=(const Fixed &new_object) const;
        bool    operator<=(const Fixed &new_object) const;
        bool    operator==(const Fixed &new_object) const;
        bool    operator!=(const Fixed &new_object) const;
        Fixed   operator+(const Fixed &new_object) const;
        Fixed   operator-(const Fixed &new_object) const;
        Fixed   operator*(const Fixed &new_object) const;
        Fixed   operator/(const Fixed &new_object) const;
        Fixed&  operator++(void);
        Fixed   operator++(int);
        Fixed&  operator--(void);
        Fixed   operator--(int);
        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif