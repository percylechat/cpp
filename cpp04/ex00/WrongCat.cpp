#include "WrongCat.hpp"

WrongCat::WrongCat( std::string type )
{
    std::cout << "Default WrongCat constructor called" << std::endl;
    this->settype(type);
}

WrongCat::WrongCat( void )
{
    std::cout << "True default WrongCat constructor called" << std::endl;
    this->settype("WrongCat");
}

WrongCat::WrongCat( const WrongCat &one )
{
    std::cout << "Copy WrongCat constructor called" << std::endl;
    *this = one;
}

WrongCat& WrongCat::operator=( const WrongCat& one )
{
    std::cout << "WrongCat Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    this->settype(one.WrongCat::getType());
    return (*this);
}

WrongCat::~WrongCat( void )
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

std::string WrongCat::getType() const
{
    return (this->WrongAnimal::getType());
}

void WrongCat::makeSound( void ) const
{
    std::cout << "Miaou Miaou" << std::endl;
}