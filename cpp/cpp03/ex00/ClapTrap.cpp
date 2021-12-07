#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name )
{
    std::cout << "Default constructor called" << std::endl;
    this->name = name;
    this->Hitpoints = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap( void )
{
    std::cout << "True default constructor called" << std::endl;
    this->name = "Default";
    this->Hitpoints = 10;
    this->Energy_points = 10;
    this->Attack_damage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &one )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = one;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &one )
{
    std::cout << "Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    name = one.name;
    Hitpoints = one.Hitpoints;
    Energy_points = one.Energy_points;
    Attack_damage = one.Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack( std::string const & target )
{
    std::cout <<"ClapTrap " << this->name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    std::cout <<"ClapTrap " << this->name << " is hurt. He takes " << amount << " points of damage!" << std::endl;
    this->Hitpoints = this->Hitpoints - amount;
    if (this->Hitpoints > 0)
        std::cout <<"ClapTrap " << this->name << " has only " << this->Hitpoints << " PVs left."  << std::endl;
    else
        std::cout <<"ClapTrap " << this->name << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout <<"ClapTrap " << this->name << " gets repaired. He gains " << amount << " PVs" << std::endl;
    this->Hitpoints += amount;
    if (this->Hitpoints > 10)
    {
        this->Hitpoints = 10;
        std::cout <<"ClapTrap " << this->name << " is full life." << std::endl;
    }
    else
        std::cout <<"ClapTrap " << this->name << " has " << this->Hitpoints << " PVs." << std::endl;
}