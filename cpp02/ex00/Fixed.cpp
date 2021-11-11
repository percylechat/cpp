#include "Fixed.hpp"

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->point_value = 0;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &one )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = one;
}

Fixed& Fixed::operator=(const Fixed &one)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
	point_value = one.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return point_value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    point_value = raw;
}