#include "Fixed.hpp"

Fixed::Fixed( void )
{
    // std::cout << "Default constructor called" << std::endl;
    this->point_value = 0;
}

Fixed::~Fixed( void )
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &one )
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = one;
}

Fixed& Fixed::operator=(const Fixed &one)
{
    // std::cout << "Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
	point_value = one.getRawBits();
	return (*this);
}

int Fixed::operator<( const Fixed& one )
{
    if (this->getRawBits() < one.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator>( const Fixed& one )
{
    if (this->getRawBits() > one.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator>=( const Fixed& one )
{
    if (this->getRawBits() >= one.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator<=( const Fixed& one )
{
    if (this->getRawBits() <= one.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator!=( const Fixed& one )
{
    if (this->getRawBits() != one.getRawBits())
        return 1;
    return 0;
}

int Fixed::operator==( const Fixed& one )
{
    if (this->getRawBits() == one.getRawBits())
        return 1;
    return 0;
}

Fixed Fixed::operator+( const Fixed& one )
{
    return Fixed(this->toFloat() + one.toFloat());
}

Fixed Fixed::operator-( const Fixed& one )
{
    return Fixed(this->toFloat() - one.toFloat());
}

Fixed Fixed::operator*( const Fixed& one )
{
    return Fixed(this->toFloat() * one.toFloat());
}

Fixed Fixed::operator/( const Fixed& one )
{
    return Fixed(this->toFloat() / one.toFloat());
}

Fixed& Fixed::operator++( void )
{
    this->point_value++;
    // this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed& Fixed::operator--( void )
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed Fixed::operator++( int nbr )
{
    Fixed *temp;
    temp = this;

    if (nbr != 0)
        this->setRawBits(this->getRawBits() + nbr);
    else
        this->setRawBits(this->getRawBits() + 1);
   return (*temp);
    //    Fixed tmp = *this;
	// this->point_value++;
	// return tmp;
}

Fixed Fixed::operator--( int nbr )
{
    Fixed *temp;
    temp = this;

    if (nbr != 0)
        this->setRawBits(this->getRawBits() - nbr);
    else
        this->setRawBits(this->getRawBits() - 1);
   return (*temp);
}

const Fixed& Fixed::max( Fixed const &one, Fixed const &two )
{
    if (one.getRawBits() > two.getRawBits())
        return (one);
    return (two);
}

Fixed &Fixed::max( Fixed &one, Fixed &two)
{
    if (one.getRawBits() > two.getRawBits())
        return (one);
    return (two);
}

const Fixed& Fixed::min( Fixed const &one, Fixed const &two )
{
    if (one.getRawBits() < two.getRawBits())
        return (one);
    return (two);
}

Fixed &Fixed::min( Fixed &one, Fixed &two)
{
    if (one.getRawBits() < two.getRawBits())
        return (one);
    return (two);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return point_value;
}

void Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    point_value = raw;
}

Fixed::Fixed ( const int nbr )
{
    // std::cout << "Int constructor called" << std::endl;
	this->point_value = nbr << bit_nbr;
}

Fixed::Fixed (const float nbr)
{
    // std::cout << "Float constructor called" << std::endl;
    this->point_value = round(nbr * (float)(1 << bit_nbr));
    // std::cout << this->point_value;
}

float Fixed::toFloat(void) const
{
    return ((float)point_value / (float)(1 << bit_nbr));
}

int Fixed::toInt(void) const
{
    return (point_value / (1 << bit_nbr));
}

std::ostream& operator<<(std::ostream& os, const Fixed &test)
{
    return os << test.toFloat();
}