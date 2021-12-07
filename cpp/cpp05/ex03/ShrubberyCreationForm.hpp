#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    public:
        ShrubberyCreationForm( void );
        ShrubberyCreationForm( const std::string target );
        ShrubberyCreationForm( const ShrubberyCreationForm& );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& );
        ~ShrubberyCreationForm( void );
        void execute (Bureaucrat const & executor) const;
    private:
        std::string target;
};

#endif 