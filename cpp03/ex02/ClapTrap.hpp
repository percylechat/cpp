#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>

class ClapTrap
{
    public:
        ClapTrap( std::string );
        ClapTrap( void );
        ClapTrap( const ClapTrap& );
        ClapTrap& operator=( const ClapTrap & );
        ~ClapTrap( void );
        void attack( std::string const & );
        void takeDamage( unsigned int );
        void beRepaired( unsigned int );
        std::string getname( void ) const ;
        int gethp( void ) const;
        int getep( void ) const ;
        int getad( void )const ;
        void setname( std::string name );
        void sethp( int amount );
        void setep( int amount );
        void setad( int amount );
    private:
        std::string name;
        int Hitpoints;
        int Energy_points;
        int Attack_damage;
};

#endif