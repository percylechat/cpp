#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    public:
    //constructeur
        Zombie();
        // Zombie(std::string);
    //destructeur
        ~Zombie( void );
        void announce( void );
        void set_name(std::string name);
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif