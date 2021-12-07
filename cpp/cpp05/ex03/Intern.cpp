#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern( const Intern &one )
{
    //CHEcK FUNC
    *this = one;
}

Intern::Intern()
{

};

Intern& Intern::operator=( const Intern &one )
{
    if (this == &one)
		return (*this);
	return (*this);
}

Intern::~Intern( void )
{
}

Form* Intern::makeForm(std::string name, std::string target)
{
    std::string forms[] =
    {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	Form *templateform[]=
    {
		new RobotomyRequestForm(target),
		new ShrubberyCreationForm(target),
		new PresidentialPardonForm(target)
	};

    int i = 0;
    while (i < 3)
    {
        if (forms[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return templateform[i];
        }
        i++;
    }
    std::cout << "Intern couldn't create " << name << ". It is not a proper Form." << std::endl;
    return (NULL);
}