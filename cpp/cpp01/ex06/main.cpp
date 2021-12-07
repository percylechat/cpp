#include "Karen.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Wrong arguments !" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    Karen test;
    test.complain(input);
    return 0;
}