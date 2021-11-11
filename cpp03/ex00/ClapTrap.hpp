#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap( void );
        ClapTrap( std::string );
        ClapTrap( const ClapTrap& );
        ClapTrap& operator=( const ClapTrap& );
        ~ClapTrap( void );
        void attack( std::string const & );
        void takeDamage( unsigned int );
        void beRepaired( unsigned int );
    private:
        std::string name;
        int Hitpoints;
        int Energy_points;
        int Attack_damage;
};

#endif