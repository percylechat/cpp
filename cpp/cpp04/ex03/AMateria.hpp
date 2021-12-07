#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria(std::string const & type);
        AMateria(void);
        AMateria( const AMateria & );
        AMateria& operator=( const AMateria & );
        virtual ~AMateria(void);
        std::string const & getType() const;
        void setType( std::string type );
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif