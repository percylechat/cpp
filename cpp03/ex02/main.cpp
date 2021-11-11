
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
int main(){
    ScavTrap One("John");
    ClapTrap Two("Betty");
    FragTrap Three("Lisa");
    One.guardGate();
    Three.highFivesGuys();
    Two.attack("John");
    One.takeDamage(5);
    One.beRepaired(3);
    One.beRepaired(3);
    One.takeDamage(12);
}