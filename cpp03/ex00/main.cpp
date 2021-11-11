// Files to turn in : Makefile ClapTrap.cpp ClapTrap.hpp main.cpp
// Forbidden functions : None
// Here you have to make a class! How original!
// The class will be called ClapTrap, and will have the following private attributes,
// initialized to the specified values:
// •Name (Parameter of constructor)
// •Hitpoints (10)
// •Energy points (10)
// •Attack damage (0)
// You will also give it a few public functions to make it more life-like:
// •void attack(std::string const & target)
// •void takeDamage(unsigned int amount)
// •void beRepaired(unsigned int amount)
// In all of these functions, you have to display something to describe what happens.
// For example, the attack function may display something along the lines of:
// ClapTrap <name> attack <target>, causing <damage> points of damage!
// The constructor and destructor must also display something, so people can see they
// have been called.
// You will provide a main function, with enough tests to demonstrate that your code is
// functional.

#include "ClapTrap.hpp"
int main(){
    ClapTrap One("John");
    One.attack("Robert");
    One.takeDamage(5);
    One.beRepaired(3);
    One.beRepaired(3);
    One.takeDamage(12);
}