#include "Zombie.hpp"

Zombie* newZombie( std::string name )
{
    Zombie *new_one = new Zombie(name);
    return (new_one);
}