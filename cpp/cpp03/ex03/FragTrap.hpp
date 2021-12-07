#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap( std::string name );
        FragTrap( void );
        FragTrap( const FragTrap& );
        FragTrap& operator=( const FragTrap & );
        ~FragTrap( void );
        void attack( std::string const & );
        void takeDamage( unsigned int );
        void beRepaired( unsigned int );
        void highFivesGuys(void);
        std::string getname( void ) const;
        void modhp(int amount);
        void modep(int amount);
        void modad(int amount);
    private:
};

#endif