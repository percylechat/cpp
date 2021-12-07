#include "Zombie.hpp"

// Zombie::Zombie(std::string name): name(name)
// {
// }

Zombie::Zombie()
{
}

Zombie::~Zombie( void )
{
    std::cout << Zombie::name << " died, for good this time." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << "<" << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string name)
{
   this->name = name;
}