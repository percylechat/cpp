#include <iostream>
#include "iter.hpp"

template <typename T>
void increase(T & i )
{
	i = i + 1;
}

int main(){
    int array[10];

    int i = 0;
    while ( i < 10) 
    {
        array[i] = i;
        std::cout << array[i] << std::endl;
        i++;
    }
    iter(array, 10, increase);
    i = 0;
    std::cout << "_________________________________" << std::endl;
    while ( i < 10) 
    {
        std::cout << array[i] << std::endl;
        i++;
    }
    std::cout << "_________________________________" << std::endl;
    char arrai[10];
    i = 0;
    while ( i < 10) 
    {
        arrai[i] = 'a' + i;
        std::cout << arrai[i] << std::endl;
        i++;
    }
    iter(arrai, 10, increase);
    i = 0;
    std::cout << "_________________________________" << std::endl;
    while ( i < 10) 
    {
        std::cout << arrai[i] << std::endl;
        i++;
    }
}