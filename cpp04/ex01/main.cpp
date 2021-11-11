// You’ll reuse the Ex00 classes.
// Create one class called Brain.
// Brain will contain an array of 100 std::string called ideas
// Now, Dog and cat will have a private Brain* attribute.
// Not every animal got a brain!
// Upon construction Dog and Cat will initialize their Brain* with a new Brain();
// Upon destruction Dog and Cat will delete their Brain.
// Your main will create and fill an Array of Animal half of it will be Dog and the other
// half will be Cat.
// Before exit, your main will loop over this array and delete every Animal.
// You must delete directly Cat and Dog as an Animal.
// A copy of a Cat or Dog must be "deep".
// Your test should show that copies are deep!
// Constructors and destructors of each class must have specifics output.
// The appropriate destructors must be called.
#include "Dog.hpp"
#include "Cat.hpp"
int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    Animal* test[10];
    int k = 0;
    while (k < 10)
    {
        if (k % 2 == 0)
            test[k] = new Cat();
        else
            test[k] = new Dog();
        k++;
    }
    int l = 0;
    while (l < 10)
    {
        delete test[l];
        l++;
    }
}