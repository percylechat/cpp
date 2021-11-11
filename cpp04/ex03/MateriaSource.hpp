#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"

// learnMateria must copy the Materia passed as a parameter, and store it in memory
// to be cloned later. Much in the same way as for Character , the Source can know at
// most 4 Materia, which are not necessarily unique.
// createMateria(std::string const &) will return a new Materia, which will be a
// copy of the Materia (previously learned by the Source) which type equals the parameter.
// Returns 0 if the type is unknown.
// In a nutshell, your Source must be able to learn "templates" of Materia and re-create
// them on demand. You’ll then be able to create a Materia without knowing its "real" type,
// just a string identifying it.

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