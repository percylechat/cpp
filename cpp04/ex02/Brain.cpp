#include "Brain.hpp"

Brain::Brain( void )
{
    std::cout << "True default Brain constructor called" << std::endl;
}

Brain::Brain( const Brain &one )
{
    std::cout << "Copy Brain constructor called" << std::endl;
    *this = one;
}

Brain& Brain::operator=( const Brain & one)
{
    std::cout << "Brain Assignation operator called" << std::endl;
    if (this == &one)
		return (*this);
    return (*this);
}

Brain::~Brain( void )
{
    std::cout << "Brain Destructor called" << std::endl;
}
