#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat( std::string type );
        Cat( void );
        Cat( const Cat &one );
        Cat& operator=( const Cat & );
        ~Cat( void );
        std::string getType( void ) const;
        void virtual makeSound( void ) const;
    private:
};

#endif