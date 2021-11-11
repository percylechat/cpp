#ifndef HUMANA_H
#define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void attack( void );
    private:
        std::string name;
        Weapon &weapon;
};

#endif