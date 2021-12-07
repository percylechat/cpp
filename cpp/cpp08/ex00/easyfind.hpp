#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

template <typename T>
int easyfind(T &cont, int i)
{
    typename T::iterator go = std::find(cont.begin(), cont.end(), i);
    if (go == cont.end() && *go != i)
        throw std::out_of_range("Not found");
    return *go; 
}

#endif