#include "Cat.hpp"

Cat::Cat( std::string type )
{
    std::cout << "Default Cat constructor called" << std::endl;
    this->settype(type);
    this->mind = new Brain();
}

Cat::Cat( void )
{
    std::cout << "True default Cat constructor called" << std::endl;
    this->settype("Cat");
    this->mind = new Brain();
}

Cat::Cat( const Cat &one )
{
    std::cout << "Copy Cat constructor called" << std::endl;
    *this = one;
}

Cat& Cat::operator=( const Cat& one )
{
    std::cout << "Cat Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    this->settype(one.Cat::getType());
    this->mind = one.mind;
    return (*this);
}

Cat::~Cat( void )
{
    std::cout << "Cat Destructor called" << std::endl;
    delete this->mind;
}

std::string Cat::getType() const
{
    return (this->Animal::getType());
}

void Cat::makeSound( void ) const
{
    std::cout << "Meow Meow" << std::endl;
}