#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:

    public:
        AMateria(std::string const & type);
        AMateria(void);
        AMateria( const AMateria & );
        AMateria& operator=( const AMateria & );
        virtual ~AMateria(void);
        std::string const & getType() const; //Returns the materia type
        void setType( std::string type );
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
    private:
        std::string type;
};

#endif