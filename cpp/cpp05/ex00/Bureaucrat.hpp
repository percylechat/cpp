#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat( void );
        Bureaucrat( const std::string , int );
        Bureaucrat( const Bureaucrat& );
        Bureaucrat& operator=( const Bureaucrat& );
        ~Bureaucrat( void );
        const std::string getName() const;
        int getGrade() const;
        void increaseGrade();
        void decreaseGrade();
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
};

std::ostream& operator<<(std::ostream& os, Bureaucrat &test);

#endif // !BUREAUCRAT_H