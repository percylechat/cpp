#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
    public:
        RobotomyRequestForm( void );
        RobotomyRequestForm( const std::string target );
        RobotomyRequestForm( const RobotomyRequestForm& );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& );
        ~RobotomyRequestForm( void );
        void execute (Bureaucrat const & executor) const;
    private:
        std::string target;
};

#endif 