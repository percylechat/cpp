//For every exercise, your main must test everything.
// Constructors and destructors of each class must have specifics output.
// Create a simple and complete base class Animal.
// The animal class got one protected attribute:
// •std::string type;
// Create a class Dog that inherits from Animal.
// Create a class Cat that inherits from Animal.
// (for the animal class the type can be left empty or put at any value).
// Every class should put their name in the Type field for example:
// The Dog class type must be initialized as "Dog".
// Every animal must be able to use the method makeSound().
// This method will display an appropriate message on the standard outputs based on the
// class.

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
    protected:
        Animal( std::string type );
        Animal( void );
        Animal( const Animal &one );
        Animal& operator=( const Animal & );
    public:
        virtual ~Animal( void );
        std::string getType( void ) const;
        void settype( std::string );
        //si l'animal n'avait pas son propre son, mettre = 0 a la fin pour pas de fonction precise pour classe de base
        void virtual makeSound( void ) const;
    private:
        std::string type;
};

#endif