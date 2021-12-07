#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice( void )
{
    this->setType("ice");
}

Ice::Ice( const Ice &one )
{
    *this = one;
}

Ice& Ice::operator=( const Ice &one )
{
    if (this == &one)
		return (*this);
    return (*this);
}

Ice::~Ice() 
{
}

Ice* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}