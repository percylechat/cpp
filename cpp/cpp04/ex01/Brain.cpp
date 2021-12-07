#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "True default Brain constructor called" << std::endl;
    int i = 0;
    while (i < 100)
    {
        ideas[i] = "thoughts";
        i++;
    }
}

Brain::Brain( const Brain &one )
{
    std::cout << "Copy Brain constructor called" << std::endl;
    *this = one;
    int i = 0;
    while (i < 100)
    {
        ideas[i] = one.ideas[i];
        i++;
    }
}

Brain& Brain::operator=( const Brain & one)
{
    std::cout << "Brain Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    int i = 0;
    while (i < 100)
    {
        ideas[i] = one.ideas[i];
        i++;
    }
    return (*this);
}

Brain::~Brain( void )
{
    // delete [] ideas;
    std::cout << "Brain Destructor called" << std::endl;
}
