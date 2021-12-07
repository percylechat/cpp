#include "Character.hpp"

Character::Character( std::string type )
{
    this->type = type;
    this->index = 0;
    int i = 0;
    while (i < 4)
        this->inventory[i++] = NULL;
}

Character::Character( void )
{
    this->type = "Random";
    this->index = 0;
    int i = 0;
    while (i < 4)
        this->inventory[i++] = NULL;
}

Character::Character( const Character &one )
{
    this->type = one.type;
    this->index = one.index;
    if (this->index != 0)
    {
        int i = 0;
        while (i < this->index)
        {
            this->inventory[i] = one.inventory[i]->clone();
            i++;
        }
        while (i < 4)
        {
            this->inventory[i] = NULL;
            i++;
        }
    }
}

Character& Character::operator=( const Character &one )
{
    if (this == &one)
		return (*this);
    this->type = one.type;
    this->index = one.index;
    if (this->index != 0)
    {
        int i = 0;
        while (i < this->index)
        {
            this->inventory[i] = one.inventory[i]->clone();
            i++;
        }
        while (i < 4)
        {
            this->inventory[i] = NULL;
            i++;
        }
    }
    return (*this);
}

Character::~Character() 
{
    if (this->index != 0)
    {
        int i = 0;
        while (i < this->index)
        {
            if (this->inventory[i])
            {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
            i++;
        }
    }
}

std::string const & Character::getName() const 
{
    return this->type;
}

void Character::equip(AMateria* m) 
{
    if (this->index >= 4)
        return;
    this->inventory[this->index] = m;
    this->index++;
}

void Character::unequip(int idx) 
{
    if (idx > this->index || idx < 0)
        return ;
    delete this->inventory[idx];
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) 
{
    if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
        return;
    this->inventory[idx]->use(target);
}