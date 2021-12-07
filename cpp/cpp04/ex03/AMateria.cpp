#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

AMateria::AMateria()
{
    this->type = "Default";
}

AMateria::AMateria( const AMateria &one )
{
    *this = one;
    this->type = one.type;
}

AMateria& AMateria::operator=( const AMateria &one )
{
    if (this == &one)
		return (*this);
    // this->type = one.type;
    return (*this);
}

AMateria::~AMateria(void)
{
}

std::string const & AMateria::getType() const
{
    return this->type;
}

void AMateria::setType( std::string type )
{
    this->type = type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "A materia is used on " << target.getName() << std::endl;
}