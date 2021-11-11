// Files to turn in : Makefile, main.cpp, Weapon.cpp, Weapon.hpp, HumanA.cpp,
// HumanA.hpp, HumanB.cpp, HumanB.hpp

// Make a Weapon class, that has a type string, and a getType method that returns a
// const reference to this string. It also has a setType, of course!
// Now, create two classes, HumanA and HumanB, that both have a Weapon, a name, and
// an attack() function that displays:
// NAME attacks with his WEAPON_TYPE
// HumanA and HumanB are almost-almost the same; there are only two tiny-little-minuscule
// details:
// •While HumanA takes the Weapon in its constructor, HumanB doesn’t.
// •HumanB may not always have a Weapon, but HumanA will ALWAYS be armed.

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
}
