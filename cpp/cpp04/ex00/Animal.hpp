#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    public:
        Animal( std::string type );
        Animal( void );
        Animal( const Animal &one );
        Animal& operator=( const Animal & );
        virtual ~Animal( void );
        std::string getType( void ) const;
        void settype( std::string );
        void virtual makeSound( void ) const;
    protected:
        std::string type;
};

#endif