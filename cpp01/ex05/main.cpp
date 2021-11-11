#include "Karen.hpp"

int main()
{
    std::cout << "Welcome to KarenSimulator. Let's do some tests" << std::endl;
    Karen test;
    std::cout << "First one with debug" << std::endl;
    test.complain("debug");
    std::cout << "Now warning" << std::endl;
    test.complain("warning");
    std::cout << "some random stuff" << std::endl;
    test.complain("chicken");
    std::cout << "the max level: error" << std::endl;
    test.complain("error");
    std::cout << "info" << std::endl;
    test.complain("info");
    std::cout << "an empty string" << std::endl;
    test.complain("");
}