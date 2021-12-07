#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
    sethp(100);
    setep(50);
    setad(20);
}

ScavTrap::ScavTrap( void ) : ClapTrap()
{
    std::cout << "Default constructor ScavTrap called" << std::endl;
    sethp(100);
    setep(50);
    setad(20);
}

ScavTrap::ScavTrap( const ScavTrap& one )
{
    std::cout << "Copy constructor ScavTrap called" << std::endl;
    *this = one;
}

ScavTrap& ScavTrap::operator=( const ScavTrap &one )
{
    std::cout << "Assignation operator ScavTrap called" << std::endl;
    if (this == &one)
		return (*this);
    this->setname(one.getname());
    this->sethp(one.gethp());
    this->setep(one.getep());
    this->setad(one.getad());
	return (*this);
}

ScavTrap::~ScavTrap( void )
{
    std::cout << "Destructor ScavTrap called" << std::endl;
}

void ScavTrap::attack( std::string const & target )
{
    std::cout <<"ScavTrap " << this->getname() << " attacks " << target << ", causing " << this->getad() << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage( unsigned int amount )
{
    std::cout <<"ScavTrap " << this->getname() << " is hurt. He takes " << amount << " points of damage!" << std::endl;
    sethp(this->gethp() - amount);
    if (this->gethp() > 0)
        std::cout <<"ScavTrap " << this->getname() << " has only " << this->gethp() << " PVs left."  << std::endl;
    else
        std::cout <<"ScavTrap " << this->getname() << " is dead!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    std::cout <<"ScavTrap " << this->getname() << " gets repaired. He gains " << amount << " PVs" << std::endl;
    sethp(this->gethp() + amount);
    if (this->gethp() > 100)
    {
        this->sethp(100);
        std::cout <<"ScavTrap " << this->getname() << " is full life." << std::endl;
    }
    else
        std::cout <<"ScavTrap " << this->getname() << " has " << this->gethp() << " PVs." << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "Scavtrap " << this->getname() << " is guarding the door. Sanctuary is safe!" << std::endl;
}