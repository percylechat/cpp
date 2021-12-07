#include "Dog.hpp"

Dog::Dog( std::string type )
{
    std::cout << "Default Dog constructor called" << std::endl;
    this->settype(type);
    this->mind = new Brain();
}

Dog::Dog( void )
{
    std::cout << "True default Dog constructor called" << std::endl;
    this->settype("Dog");
    this->mind = new Brain();
}

Dog::Dog( const Dog &one )
{
    std::cout << "Copy Dog constructor called" << std::endl;
    this->mind = new Brain(*one.mind);
}

Dog& Dog::operator=( const Dog& one )
{
    std::cout << "Dog Assignation operator called" << std::endl;
    this->settype(one.Dog::getType());
    this->mind = new Brain(*one.mind);
    return (*this);
}

Dog::~Dog( void )
{
    std::cout << "Dog Destructor called" << std::endl;
    delete this->mind;
}

std::string Dog::getType() const
{
    return (this->Animal::getType());
}

void Dog::makeSound( void ) const
{
    std::cout << "Wof Wof" << std::endl;
}