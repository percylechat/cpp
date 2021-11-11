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
        // void setGrade_s(int n);
        // void setGrade_e(int n);
        int getGrade_s() const;
        int getGrade_e() const;
        void beSigned(Bureaucrat &one);
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
        bool signature;
        const int grade_s;
        const int grade_e;
};

std::ostream& operator<<(std::ostream& os, Form &test);

#endif // !BUREAUCRAT_H