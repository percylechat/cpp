#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( const std::string name , int grade ) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &one )
{
    //CHEcK FUNC
    *this = one;
}

Bureaucrat::Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &one )
{
    if (this == &one)
		return (*this);
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
}

const std::string Bureaucrat::getName()
{
    return (this->name);
}

int Bureaucrat::getGrade()
{
    return (this->grade);
}

void Bureaucrat::increaseGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decreaseGrade()
{
    if (grade + 1 > 150)
        throw GradeTooHighException();
    this->grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat &test)
{
    os << test.getName() << ", bureaucrat grade " << test.getGrade() << std::endl;
}

std::string Bureaucrat::GradeTooLowException::error_low() const throw()
{
    return "Error: this Bureaucrat would be too low on the totem pole";
}

std::string Bureaucrat::GradeTooHighException::error_high() const throw()
{
    return "Error: this Bureaucrat would be too qualified";
}