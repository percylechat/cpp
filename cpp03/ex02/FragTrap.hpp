// Chapter IV
// Exercise 02: Repetitive work
// Exercise : 02
// Repetitive work
// Turn-in directory : ex02/
// Files to turn in : Same as previous exercise + FragTrap.cpp FragTrap.hpp
// Forbidden functions : None
// Making Claptraps is probably starting to get on your nerves.
// Now, you will make a FragTrap class that inherits from ClapTrap.
// •Name (Parameter of constructor)
// •Hitpoints (100)
// •Energy points (100)
// •attack damage (30)
// The FragTrap class will have its construction and destruction messages. Also, proper
// construction/destruction chaining must be present (When you build a FragTrap, you
// must start by building a ClapTrap... Destruction is in reverse order), and the tests have
// to show it.
// The specific function for FragTrap will be void highFivesGuys(void) and will dis-
// play a positive high fives request on the standard output.
// Extend your main function to test everything

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
    private:
};

#endif