#ifndef DOG_H
#define DOG_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog( std::string type );
        Dog( void );
        Dog( const Dog &one );
        Dog& operator=( const Dog & );
        ~Dog( void );
        std::string getType( void ) const;
        void virtual makeSound( void ) const;
    private:
        Brain *mind;
};

#endif