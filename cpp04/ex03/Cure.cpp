#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure( void )
{
    this->setType("cure");
}

Cure::Cure( const Cure &one )
{
    *this = one;
}

Cure& Cure::operator=( const Cure &one )
{
    if (this == &one)
		return (*this);
    return (*this);
}

Cure::~Cure() 
{
    //destroy materias
}

Cure* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}