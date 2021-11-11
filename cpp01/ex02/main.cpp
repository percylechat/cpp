#include <iostream>

int main()
{
    std::string text = "HI THIS IS BRAIN";
    std::string *stringPTR = &text;
    std::string &stringREF = text;

    std::cout << "Print content " << text << std::endl;
    std::cout << "Print address " << &text << std::endl;
    std::cout << "Print address with pointer " << stringPTR << std::endl;
    std::cout << "Print address with ref " << &stringREF << std::endl;
}