#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap( std::string name );
        DiamondTrap( void );
        DiamondTrap( const DiamondTrap& );
        DiamondTrap& operator=( const DiamondTrap & );
        ~DiamondTrap( void );
        void whoAmI( void );
        void attack(std::string const & target);
    private:
        std::string name;
};

#endif