#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    public:
    //constructeur
        Zombie(std::string);
    //destructeur
        ~Zombie( void );
        void announce( void );
    private:
        std::string name;
};

    Zombie* newZombie( std::string name );
    void randomChump( std::string name );

#endif