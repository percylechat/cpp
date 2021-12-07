#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void )
{
    this->index = 0;
}

MateriaSource::MateriaSource( const MateriaSource &one )
{
    *this = one;
}

MateriaSource& MateriaSource::operator=( const MateriaSource &one )
{
    if (this == &one)
		return (*this);
    return (*this);
}

MateriaSource::~MateriaSource() 
{
    int i = 0;
    while (i < this->index)
    {
        delete this->templates[i];
        i++;
    }
    //destroy materias
}

void MateriaSource::learnMateria(AMateria* one)
{
    if (this->index == 3)
        return;
    this->templates[this->index] = one;
    this->index++;
    // delete one;
    // this->templates[this->index] = one;
    // this->index++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i = 0;
    while (i < this->index)
    {
        if (!type.compare(this->templates[i]->getType()))
            return this->templates[i]->clone();
        i++;
    }
    return NULL;
}