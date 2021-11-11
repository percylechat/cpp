#include "FragTrap.hpp"

#include "ClapTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    std::cout << "Default constructor FragTrap called" << std::endl;
    sethp();
    setep();
    setad();
}

FragTrap::FragTrap( void ) : ClapTrap()
{
    std::cout << "Default constructor FragTrap called" << std::endl;
    sethp();
    setep();
    setad();
}

FragTrap::FragTrap( const FragTrap& one )
{
    std::cout << "Copy constructor FragTrap called" << std::endl;
    *this = one;
}

FragTrap& FragTrap::operator=( const FragTrap &one )
{
    std::cout << "Assignation operator FragTrap called" << std::endl;
    if (this == &one)
		return (*this);
    this->setname(one.getname());
    this->modhp(one.gethp());
    this->modep(one.getep());
    this->modad(one.getad());
	return (*this);
}

FragTrap::~FragTrap( void )
{
    std::cout << "Destructor FragTrap called" << std::endl;
}

void FragTrap::attack( std::string const & target )
{
    std::cout <<"FragTrap " << this->getname() << " attacks " << target << ", causing " << this->getad() << " points of damage!" << std::endl;
}

void FragTrap::takeDamage( unsigned int amount )
{
    std::cout <<"FragTrap " << this->getname() << " is hurt. He takes " << amount << " points of damage!" << std::endl;
    modhp(this->gethp() - amount);
    if (this->gethp() > 0)
        std::cout <<"FragTrap " << this->getname() << " has only " << this->gethp() << " PVs left."  << std::endl;
    else
        std::cout <<"FragTrap " << this->getname() << " is dead!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    std::cout <<"FragTrap " << this->getname() << " gets repaired. He gains " << amount << " PVs" << std::endl;
    modhp(this->gethp() + amount);
    if (this->gethp() > 100)
    {
        this->sethp();
        std::cout <<"FragTrap " << this->getname() << " is full life." << std::endl;
    }
    else
        std::cout <<"FragTrap " << this->getname() << " has " << this->gethp() << " PVs." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->getname() << " wants a high five!" << std::endl;
}

std::string FragTrap::getname( void ) const
{
    return (this->name);
}

void FragTrap::sethp()
{
    this->ClapTrap::sethp(100);
}

void FragTrap::setep()
{
    this->ClapTrap::setep(100);
}

void FragTrap::setad()
{
    this->ClapTrap::sethp(30);
}

void FragTrap::modhp(int amount)
{
    this->ClapTrap::sethp(amount);
}

void FragTrap::modep(int amount)
{
    this->ClapTrap::setep(amount);
}

void FragTrap::modad(int amount)
{
    this->ClapTrap::sethp(amount);
}