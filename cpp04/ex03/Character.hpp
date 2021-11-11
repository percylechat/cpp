#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
    public:
        Character( std::string type );
        Character( void );
        Character( const Character &one );
        Character& operator=( const Character & );
        ~Character();
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    private:
        AMateria* inventory[4];
        std::string type;
        int index;
};

#endif