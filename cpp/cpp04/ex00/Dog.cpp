#include "Dog.hpp"

Dog::Dog( std::string type )
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->settype(type);
}

Dog::Dog( void )
{
    std::cout << "True default Dog constructor called" << std::endl;
    this->settype("Dog");
}

Dog::Dog( const Dog &one )
{
    std::cout << "Copy Dog constructor called" << std::endl;
    *this = one;
}

Dog& Dog::operator=( const Dog& one )
{
    std::cout << "Cat Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    this->settype(one.Dog::getType());
    return (*this);
}

Dog::~Dog( void )
{
    std::cout << "Dog Destructor called" << std::endl;
}

std::string Dog::getType() const
{
    return (this->Animal::getType());
}

void Dog::makeSound( void ) const
{
    std::cout << "Wof Wof" << std::endl;
}