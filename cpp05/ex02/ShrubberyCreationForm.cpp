#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("ShrubberyCreationForm", 145, 137), target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : Form("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm( const Form& )
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const Form& )
{

}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{

}