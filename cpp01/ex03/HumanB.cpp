#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& new_weapon)
{
    weapon = &new_weapon;
}

void HumanB::attack( void )
{
    std::cout << name;
    std::cout << " attacks with his " << weapon->getType() << std::endl;
}