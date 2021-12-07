
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat i("John", 74);
        std::cout << i;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form j("Formulaire42", 0, 34);
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form j("Formulaire42", 43, 0);
    }
    catch (Form::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
        try
    {
        Form j("Formulaire42", 151, 34);
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form j("Formulaire42", 43, 151);
    }
    catch (Form::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 45);
        std::cout << k;
        Form b("Formulairebis", 30, 12);
        std::cout << b;
        k.signForm(b);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 45);
        std::cout << k;
        Form c("Formulairebis", 50, 12);
        std::cout << c;
        k.signForm(c);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}