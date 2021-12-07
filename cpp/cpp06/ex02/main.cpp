#include "Base.hpp"
#include <iostream>
#include <stdlib.h>

Base * generate(void)
{
    int i = rand() % 9 + 1;
    if (i < 4)
        return (new A);
    else if (i > 6)
        return (new B);
    else
        return (new C);
}

void identify(Base * p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
        else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
        else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "something went wrong" << std::endl;
}

void identify( Base & p)
{
    try
    {
        Base base = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    try
    {
        Base base = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception &e) {}
    try
    {
        Base base = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    } 
    catch (std::exception &e) {}
}

int main(){
    A test1;
    B test2;
    C test3;
    identify(&test1);
    identify(&test2);
    identify(&test3);
    identify(test1);
    identify(test2);
    identify(test3);
    std::cout << "__________________" << std::endl;
    int i = 0;
    while (i < 15)
    {
        Base * testing = generate();
        identify(*testing);
        identify(testing);
        i++;
    }
}