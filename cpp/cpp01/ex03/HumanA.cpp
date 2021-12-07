#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack( void )
{
    std::cout << name;
    std::cout << " attacks with his " << this->weapon.getType() << std::endl;
}