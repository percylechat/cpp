#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
    public:
        Bureaucrat( void );
        Bureaucrat( const std::string , int );
        Bureaucrat( const Bureaucrat& );
        Bureaucrat& operator=( const Bureaucrat& );
        ~Bureaucrat( void );
        const std::string getName();
        // void setName( const std::string );
        int getGrade();
        void increaseGrade();
        void decreaseGrade();
        void signForm( Form one);
    class GradeTooHighException
    {
        public:
            std::string error_high(void) const throw();
    };
    class GradeTooLowException
    {
        public:
            std::string error_low(void) const throw();
    };
    private:
        const std::string name;
        int grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat &test);

#endif // !BUREAUCRAT_H