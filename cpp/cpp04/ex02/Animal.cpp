#include "Animal.hpp"

Animal::Animal( std::string type ) : type(type)
{
    std::cout << "Default constructor called" << std::endl;
}
Animal::Animal( void )
{
    std::cout << "True default constructor called" << std::endl;
    this->type = " ";
}

Animal::Animal( const Animal &one )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = one;
}

Animal& Animal::operator=( const Animal & one )
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    this->type = one.type;
    return (*this);
}

Animal::~Animal( void )
{
    std::cout << "Destructor called" << std::endl;
}

std::string Animal::getType( void ) const
{
    return (this->type);
}

void Animal::settype( std::string type )
{
    this->type = type;
}

void Animal::makeSound( void ) const
{
    std::cout << "ksufycgbnw" << std::endl;
}