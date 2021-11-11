#ifndef WRONGCAT_H
#define WRONGCAT_H

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
    public:
        WrongCat( std::string type );
        WrongCat( void );
        WrongCat( const WrongCat &one );
        WrongCat& operator=( const WrongCat & );
        ~WrongCat( void );
        std::string getType( void ) const;
        void makeSound( void ) const;
    private:
};

#endif