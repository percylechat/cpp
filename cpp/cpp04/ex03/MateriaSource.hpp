#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    public:
        MateriaSource( void );
        MateriaSource( const MateriaSource &one );
        MateriaSource& operator=( const MateriaSource & );
        ~MateriaSource();
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
    private:
        int index;
        AMateria* templates[4];
};

#endif