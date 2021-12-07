#include "ClapTrap.hpp"
int main(){
    ClapTrap One("John");
    ClapTrap Two(One);
    ClapTrap Three = One;
    One.attack("Robert");
    One.takeDamage(5);
    One.beRepaired(3);
    One.beRepaired(3);
    One.takeDamage(12);
    Two.takeDamage(5);
    Three.takeDamage(5);
}