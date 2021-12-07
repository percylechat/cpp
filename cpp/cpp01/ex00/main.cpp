#include "Zombie.hpp"

int main()
{
    std::cout << "Hello, hope you like the Walking Dead" << std::endl;
    std::cout << "First we create our Zombie by hand" << std::endl;
    Zombie test("John");
    test.announce();
    std::cout << "Now let's do one with newZombie" << std::endl;
    Zombie *fred = newZombie("Fred");
    fred->announce();
    std::cout << "Since we used a pointer, we need to destroy it manually" << std::endl;
    delete fred;
    std::cout << "Then one with randomChump" << std::endl;
    randomChump("Dina");
    std::cout << "Yep, she died instantly because she can't be used anymore" << std::endl;
    std::cout << "Now the program will end, and John will be destroyed automatically" << std::endl;
}