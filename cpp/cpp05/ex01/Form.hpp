#ifndef FORM_H
#define FORM_H

#include <iostream>

class Bureaucrat;

class Form
{
    public:
        Form( void );
        Form( const std::string name , int grade_s, int grade_e );
        Form( const Form& );
        Form& operator=( const Form& );
        ~Form( void );
        const std::string getName() const;
        int getGrade_s() const;
        int getGrade_e() const;
        Form& beSigned(Bureaucrat &one);
    class GradeTooHighException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };
    protected:
        const std::string name;
        bool signature;
        const int grade_s;
        const int grade_e;
};

std::ostream& operator<<(std::ostream& os, Form &test);

#endif 