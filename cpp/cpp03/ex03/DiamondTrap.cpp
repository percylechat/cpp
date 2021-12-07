#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap( std::string name )
{
    std::cout << "Default constructor DiamondTrap called" << std::endl;
    this->FragTrap::sethp(100);
    this->ScavTrap::setep(50);
    this->FragTrap::setad(30);
    this->name = name;
    this->ClapTrap::setname(name);
}

DiamondTrap::DiamondTrap( void )
{
    std::cout << "Default constructor DiamondTrap called" << std::endl;
    this->FragTrap::sethp(100);
    this->ScavTrap::setep(50);
    this->FragTrap::setad(30);
    this->name = " ";
}

DiamondTrap::DiamondTrap( const DiamondTrap& one )
{
    std::cout << "Copy constructor DiamondTrap called" << std::endl;
    *this = one;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap &one )
{
    std::cout << "Assignation operator DiamondTrap called" << std::endl;
    if (this == &one)
		return (*this);
    this->FragTrap::modhp(one.FragTrap::gethp());
    this->ScavTrap::modep(one.ScavTrap::gethp());
    this->FragTrap::modad(one.FragTrap::gethp());
    this->FragTrap::setname(one.FragTrap::getname());
	return (*this);
}

void    DiamondTrap::attack(std::string const & target)
{
    this->ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI( void )
{
    std::cout << "My name is " << this->name << " but my designation is " << this->ClapTrap::getname() << std::endl;
}

DiamondTrap::~DiamondTrap( void )
{
    std::cout << "Destructor DiamondTrap called" << std::endl;
}