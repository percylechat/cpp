#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("RobotomyRequestForm", 72, 45), target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : Form("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& one ) : Form(one)
{
        this->setSign(one.getSign());
    	target = one.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& one )
{
	this->setSign(one.getSign());
	target = one.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
}

void RobotomyRequestForm::execute (Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw UnsignedFormException();
    if (executor.getGrade() > this->getGrade_e())
        throw GradeTooHighException();
    std::cout << "Dzzzzziiiiit... Clang Clang... Vruuuuuut" << std::endl;
    int i = rand();
    if (i % 2 == 0)
        std::cout << this->target << " was sucessfully robotomized!" << std::endl;
    else
        std::cout << this->target << " robotomization failed..." << std::endl;
}