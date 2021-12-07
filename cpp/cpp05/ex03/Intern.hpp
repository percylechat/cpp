#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include "Form.hpp"

class Intern
{
    public:
        Intern( const Intern &one );
        Intern();
        Intern& operator=( const Intern &one );
        ~Intern( void );
        Form* makeForm(std::string name, std::string target);
};

#endif // !INTERN_H#define INTERN_H