#include <iostream>
#include <string>
#include "map.hpp"

int main(){
    ft::map<int, std::string> test;
    test.insert(ft::pair<int, std::string>(5, "bebe"));
}