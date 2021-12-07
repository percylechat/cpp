#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    // protected:
    public:
        Animal( std::string type );
        Animal( void );
        Animal( const Animal &one );
        Animal& operator=( const Animal & );

        virtual ~Animal( void );
        std::string getType( void ) const;
        void settype( std::string );
        //si l'animal n'avait pas son propre son, mettre = 0 a la fin pour pas de fonction precise pour classe de base
        void virtual makeSound( void ) const = 0;
    private:
        std::string type;
};

#endif