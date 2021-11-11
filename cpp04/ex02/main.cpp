// A general Animal doesn’t make sense after all.
// For example, it makes no sound!
// To avoid any future mistakes, the default animal class should not be instantiable.
// Fix the Animal class so nobody instantiates it by mistakes.
// The rest should work as before

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    delete j;
    delete i;

    // Animal meta;
    // Animal meta("Jeff");
    // new Animal;
    // const Animal* meta = new Animal();
    // meta->makeSound();
    // delete meta;
}