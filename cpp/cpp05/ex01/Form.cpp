#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( const std::string name , int grade_s, int grade_e ) : name(name), signature(false), grade_s(grade_s), grade_e(grade_e) 
{
    if (grade_e < 1 || grade_s < 1)
        throw GradeTooHighException();
    if (grade_e > 150 || grade_s> 150)
        throw GradeTooLowException();
}

Form::Form( const Form &one ) : name(one.getName()), signature(one.signature), grade_s(one.getGrade_s()), grade_e(one.getGrade_e())
{
    if (grade_e < 1 || grade_s < 1)
        throw GradeTooHighException();
    if (grade_e > 150 || grade_s> 150)
        throw GradeTooLowException();
}

Form::Form() : name(""), signature(false), grade_s(2), grade_e(1) 
{

};

Form& Form::operator=( const Form &one )
{
    if (this == &one)
		return (*this);
	return (*this);
}

Form::~Form( void )
{
}

const std::string Form::getName() const
{
    return (this->name);
}

int Form::getGrade_s() const
{
    return (this->grade_s);
}

int Form::getGrade_e() const
{
    return (this->grade_e);
}

std::ostream& operator<<(std::ostream& os, Form &test)
{
    return os << test.getName() << " requires a grade of " << test.getGrade_s() << " to be signed and one of "
    << test.getGrade_e() << " to be executed." << std::endl;
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Error: this Form's requirements are too low";
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Error: this Form's requirements are too high";
}

Form &    Form::beSigned(Bureaucrat &one)
{
    if (one.getGrade() > this->grade_s)
        throw GradeTooLowException();
    else
    {
        this->signature = true;
        std::cout << this->name << " has been approved." << std::endl;
    }
}