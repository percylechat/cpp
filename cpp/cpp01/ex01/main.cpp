#include "Zombie.hpp"

int main()
{
    std::cout << "Hello, hope you like the Walking Dead" << std::endl;
    std::cout << "Let's make 3 zombies" << std::endl;
    Zombie *test = zombieHorde(3, "Ethan");
    if (test == NULL)
    {
        std::cout << "you need to create at least one zombie" << std::endl;
        return 0;
    }
    int i = 0;
    while (i < 3)
    {
        test[i].announce();
        i++;
    }
    i = 0;
    std::cout << "Let's kill them" << std::endl;
    delete [] test;
    std::cout << "Let's try with zero" << std::endl;
    Zombie *test1 = zombieHorde(0, "Meredith");
    if (test1 == NULL)
        std::cout << "you need to create at least one zombie" << std::endl;
}