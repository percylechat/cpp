#ifndef ICE_H
#define ICE_H

#include "AMateria.hpp"

class Ice : public AMateria
{
    protected:
        // Ice( std::string type );
    public:
        Ice( void );
        Ice( const Ice & );
        Ice& operator=( const Ice & );
        ~Ice( void );
        Ice* clone() const;
        void use(ICharacter& target);
};

#endif