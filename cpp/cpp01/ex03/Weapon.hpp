#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

// Make a Weapon class, that has a type string, and a getType method that returns a
// const reference to this string. It also has a setType, of course!

class Weapon
{
public:
    Weapon(std::string type);
    ~Weapon();
    std::string const &getType( void );
    void setType(std::string new_type);

    std::string type;
};

#endif