#include "ScavTrap.hpp"
int main(){
    ScavTrap One("John");
    ClapTrap Two("Betty");
    One.guardGate();
    One.attack("Betty");
    One.takeDamage(5);
    One.beRepaired(3);
    One.beRepaired(3);
    One.takeDamage(12);
}