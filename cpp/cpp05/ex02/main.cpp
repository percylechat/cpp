#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(){
    try
    {
        Bureaucrat k("Robert", 140);
        std::cout << k;
        ShrubberyCreationForm b("Home");
        std::cout << b;
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 140);
        std::cout << k;
        ShrubberyCreationForm b("Home");
        std::cout << b;
        k.signForm(b);
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 40);
        std::cout << k;
        ShrubberyCreationForm b("Home");
        std::cout << b;
        k.signForm(b);
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "___________________________________" << std::endl;
    try
    {
        Bureaucrat k("Robert", 140);
        std::cout << k;
        RobotomyRequestForm b("Ford");
        std::cout << b;
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 60);
        std::cout << k;
        RobotomyRequestForm b("Ford");
        std::cout << b;
        k.signForm(b);
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 20);
        std::cout << k;
        RobotomyRequestForm b("Ford");
        std::cout << b;
        k.signForm(b);
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "___________________________________" << std::endl;
    try
    {
        Bureaucrat k("Robert", 140);
        std::cout << k;
        PresidentialPardonForm b("Marvin");
        std::cout << b;
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 12);
        std::cout << k;
        PresidentialPardonForm b("Marvin");
        std::cout << b;
        k.signForm(b);
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 2);
        std::cout << k;
        PresidentialPardonForm b("Marvin");
        std::cout << b;
        k.signForm(b);
        k.executeForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}