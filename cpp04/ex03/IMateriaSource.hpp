#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include "AMateria.hpp"

// learnMateria must copy the Materia passed as a parameter, and store it in memory
// to be cloned later. Much in the same way as for Character , the Source can know at
// most 4 Materia, which are not necessarily unique.
// createMateria(std::string const &) will return a new Materia, which will be a
// copy of the Materia (previously learned by the Source) which type equals the parameter.
// Returns 0 if the type is unknown.
// In a nutshell, your Source must be able to learn "templates" of Materia and re-create
// them on demand. You’ll then be able to create a Materia without knowing its "real" type,
// just a string identifying it.

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif