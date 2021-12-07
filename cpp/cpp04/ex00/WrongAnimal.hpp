
#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>

class WrongAnimal
{
    public:
        WrongAnimal( std::string type );
        WrongAnimal( void );
        WrongAnimal( const WrongAnimal &one );
        WrongAnimal& operator=( const WrongAnimal & );
        ~WrongAnimal( void );
        std::string getType( void ) const;
        void settype( std::string );
        void makeSound( void ) const;
    protected:
        std::string type;
};

#endif