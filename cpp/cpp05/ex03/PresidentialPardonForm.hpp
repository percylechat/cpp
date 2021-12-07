#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm : public Form
{
    public:
        PresidentialPardonForm( void );
        PresidentialPardonForm( const std::string target );
        PresidentialPardonForm( const PresidentialPardonForm& );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& );
        ~PresidentialPardonForm( void );
        void execute (Bureaucrat const & executor) const;
    private:
        std::string target;
};

#endif 