#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat( std::string type );
        Cat( void );
        Cat( const Cat &one );
        Cat& operator=( const Cat & );
        ~Cat( void );
        std::string getType( void ) const;
        void  makeSound( void ) const;
    private:
        Brain *mind;
};

#endif