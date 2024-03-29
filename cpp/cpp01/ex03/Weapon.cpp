#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : type(type)
{
}

Weapon::~Weapon()
{
}

std::string const &Weapon::getType( void )
{
    return (this->type);
}

void Weapon::setType(std::string new_type)
{
    type = new_type;
}