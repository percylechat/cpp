#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if (N <= 0)
        return NULL;
    Zombie *party = new Zombie[N];

    int i = 0;
    while (i < N)
    {
        party[i].set_name(name);
        i++;
    }
    return (party);
}