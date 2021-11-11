#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( const std::string name , int grade_s, int grade_e ) : name(name), signature(false), grade_s(grade_s), grade_e(grade_e) 
{
    if (grade_e < 1 || grade_s < 1)
        throw GradeTooHighException();
    if (grade_e > 150 || grade_s> 150)
        throw GradeTooLowException();
}

Form::Form( const Form &one ) : name(one.getName()), signature(false), grade_s(one.getGrade_s()), grade_e(one.getGrade_e())
{
    //CHEcK FUNC
    *this = one;
}

// Form::Form()
// {

// };

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

// void Form::setGrade_s(int n)
// {
//     this->grade_s = n;
// }

// void Form::setGrade_e(int n)
// {
//     this->grade_e = n;
// }

std::ostream& operator<<(std::ostream& os, Form &test)
{
    return os << test.getName() << ", requires an " << test.getGrade_s() << " grade to be signed and an "
    << test.getGrade_e() << " grade to be executed." << std::endl;
}

std::string Form::GradeTooLowException::error_low() const throw()
{
    return "Error: this Form's requirements are too low";
}

std::string Form::GradeTooHighException::error_high() const throw()
{
    return "Error: this Form's requirements are too high";
}

void    Form::beSigned(Bureaucrat &one)
{
    if (one.getGrade() > this->grade_s)
        throw GradeTooLowException();
    else
        this->signature = true;
}