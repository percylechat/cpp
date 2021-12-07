
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("Perceval", "Bender");
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	try
    {
        Bureaucrat k("Robert", 2);
        std::cout << k;
        k.signForm(*rrf);
        k.executeForm(*rrf);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}