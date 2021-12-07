#include "Bureaucrat.hpp"
int main()
{
    try
    {
        Bureaucrat i("John", 160);
        std::cout << i;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat i("John", 0);
        std::cout << i;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
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
        Bureaucrat j("Emily", 1);
        std::cout << j;
        j.increaseGrade();
        std::cout << j;
    }
    catch (Bureaucrat::GradeTooHighException & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat k("Robert", 150);
        std::cout << k;
        k.decreaseGrade();
        std::cout << k;
    }
    catch (Bureaucrat::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
}