#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <istream>

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", 145, 137), target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& one ) : Form(one)
{
    this->setSign(one.getSign());
    target = one.target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& one )
{
	this->setSign(one.getSign());
	target = one.target;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw UnsignedFormException();
    else if (executor.getGrade() > this->getGrade_e())
        throw GradeTooHighException();
    else
    {
        std::cout << "The shrubbery has been planted" << std::endl;
        std::string filename = this->target;
        filename = filename.append(".shrubbery");
        std:: ofstream file1;
        file1.open(&filename[0]);
        file1 << "       ###\n      #o###\n    #####o###\n   #o#\\#|#/###\n    ###\\|/#o#\n     # }|{  #\n       }|{";
        file1.close();
    }
}