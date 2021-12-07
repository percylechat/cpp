#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap( std::string name );
        ScavTrap( void );
        ScavTrap( const ScavTrap& );
        ScavTrap& operator=( const ScavTrap & );
        ~ScavTrap( void );
        void attack( std::string const & );
        void takeDamage( unsigned int );
        void beRepaired( unsigned int );
        void guardGate();
        void modhp(int amount);
        void modep(int amount);
        void modad(int amount);
    private:
};

#endif