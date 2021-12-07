#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : name(name)
{
    std::cout << "Default constructor called" << std::endl;
    sethp(10);
    setep(10);
    setad(0);
}

ClapTrap::ClapTrap( void ) : name("Default")
{
    std::cout << "True default constructor called" << std::endl;
    sethp(10);
    setep(10);
    setad(0);
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
    std::cout <<"ClapTrap " << this->getname() << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount )
{
    std::cout <<"ClapTrap " << this->getname() << " is hurt. He takes " << amount << " points of damage!" << std::endl;
    this->Hitpoints = this->Hitpoints - amount;
    if (this->Hitpoints > 0)
        std::cout <<"ClapTrap " << this->getname() << " has only " << this->Hitpoints << " PVs left."  << std::endl;
    else
        std::cout <<"ClapTrap " << this->getname() << " is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout <<"ClapTrap " << this->getname() << " gets repaired. He gains " << amount << " PVs" << std::endl;
    this->Hitpoints += amount;
    if (this->Hitpoints > 10)
    {
        this->Hitpoints = 10;
        std::cout <<"ClapTrap " << this->getname() << " is full life." << std::endl;
    }
    else
        std::cout <<"ClapTrap " << this->getname() << " has " << this->Hitpoints << " PVs." << std::endl;
}

void ClapTrap::setname( std::string name )
{
    this->name = name;
}

void ClapTrap::sethp( int amount )
{
    this->Hitpoints = amount;
}

void ClapTrap::setep( int amount )
{
    this->Energy_points = amount;
}

void ClapTrap::setad( int amount )
{
    this->Attack_damage = amount;
}

std::string ClapTrap::getname( void ) const
{
    return (this->name);
}

int ClapTrap::gethp( void ) const
{
    return (this->Hitpoints);
}

int ClapTrap::getep( void ) const
{
    return (this->Energy_points);
}

int ClapTrap::getad( void ) const
{
    return (this->Attack_damage);
}