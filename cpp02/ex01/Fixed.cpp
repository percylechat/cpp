#include "Fixed.hpp"

Fixed::Fixed( void )
{
    std::cout << "Default constructor called" << std::endl;
    this->point_value = 0;
}

Fixed::Fixed ( const int nbr )
{
    std::cout << "Int constructor called" << std::endl;
	this->point_value = nbr * (1 << bit_nbr);
    //plus simple : nbr << bit_nbr;
    //on decale de 8 crans dans le bit. Donc 1 donne 256 point value car 1 rang apres 128
    //0.5 donne 128 car le bit etait "apres" le debut et il arrive en 8eme position(128)
}

Fixed::Fixed (const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->point_value = roundf(nbr * (float)(1 << bit_nbr));
    // peut pas bit shift directement avec float donc on multiplie par le bit shift de 1
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

float Fixed::toFloat(void) const
{
    return ((float)point_value / (float)(1 << bit_nbr));
}

int Fixed::toInt(void) const
{
    //on redecale point value de 8 bits
    return point_value >> bit_nbr;
}

std::ostream& operator<<(std::ostream& os, const Fixed &test)
{
    return os << test.toFloat();
}