#include "Zombie.hpp"

void randomChump( std::string name )
{
    Zombie hello = Zombie(name);
    hello.announce();
}