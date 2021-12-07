#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Dog *k = new Dog();

    delete k;
        delete j;
    delete i;
    // Animal* test[10];
    // int k = 0;
    // while (k < 10)
    // {
    //     if (k % 2 == 0)
    //         test[k] = new Cat();
    //     else
    //         test[k] = new Dog();
    //     k++;
    // }
    // int l = 0;
    // while (l < 10)
    // {
    //     delete test[l];
    //     l++;
    //     std::cout << l << std::endl;
    // }
}