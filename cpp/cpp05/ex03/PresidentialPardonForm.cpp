#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("PresidentialPardonForm", 25, 5), target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : Form("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& one ) : Form(one)
{
    this->setSign(one.getSign());
    target = one.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& one )
{
	this->setSign(one.getSign());
	target = one.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
}

void PresidentialPardonForm::execute (Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw UnsignedFormException();
    if (executor.getGrade() > this->getGrade_e())
        throw GradeTooHighException();
    std::cout << this->target << " was granted pardon by Zaphod BeebleBrox himself" << std::endl;
}