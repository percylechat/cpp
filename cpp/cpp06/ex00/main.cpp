#include <iostream>
#include "Wololo.hpp"

int main (int argc, char **argv){
    if (argc != 2)
    {
        std::cout << "Wrong arguments!" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    Wololo test(input);
    test.convert();
}