#ifndef CURE_H
#define CURE_H

#include "AMateria.hpp"

class Cure : public AMateria
{
    protected:
        // Ice( std::string type );
    public:
        Cure( void );
        Cure( const Cure & );
        Cure& operator=( const Cure & );
        ~Cure( void );
        Cure* clone() const;
        void use(ICharacter& target);
};

#endif