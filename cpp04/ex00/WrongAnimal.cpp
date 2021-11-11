#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( std::string type ) : type(type)
{
    std::cout << "Default Wrong constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( void )
{
    std::cout << "True default Wrong constructor called" << std::endl;
    this->type = " ";
}

WrongAnimal::WrongAnimal( const WrongAnimal &one )
{
    std::cout << "Wrong Copy constructor called" << std::endl;
    *this = one;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal & one )
{
    std::cout << "Wrong Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    this->type = one.type;
    return (*this);
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "Wrong Destructor called" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
    return (this->type);
}

void WrongAnimal::settype( std::string type )
{
    this->type = type;
}

void WrongAnimal::makeSound( void ) const
{
    std::cout << "vldsunvcbwxb" << std::endl;
}