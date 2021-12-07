#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
    public:
        Brain( void );
        Brain( const Brain &one );
        Brain& operator=( const Brain & );
        ~Brain( void );
    private:
        std::string ideas[100];
};

#endif