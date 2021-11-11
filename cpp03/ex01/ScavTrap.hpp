#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
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
    private:
};

#endif