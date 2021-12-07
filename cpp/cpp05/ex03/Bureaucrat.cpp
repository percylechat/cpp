#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( const std::string name , int grade ) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &one ) : name(one.name), grade(one.grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name(""), grade(150)
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

int Bureaucrat::getGrade() const
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
    return os << test.getName() << ", bureaucrat grade " << test.getGrade() << std::endl;
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Error: this Bureaucrat would be too low on the totem pole";
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Error: this Bureaucrat would be too qualified";
}

void    Bureaucrat::signForm( Form &one)
{
    try
    {
        one.beSigned(*this);
        std::cout << this->getName() << " signs " << one.getName() << std::endl;
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cout << this->getName() << " cannot do that because their superiors said no." << std::endl;
    }
}

void Bureaucrat::executeForm (Form const & form)
{
    try 
    {
        form.execute(*this);
        std::cout << this->getName() << " executes " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}