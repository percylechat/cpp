#include <iostream>
#include <string>
// #include "vectorbis.hpp"
// #include "iterator_vector.hpp"
// #include <stdlib.h>
#include <vector>
// #include "stack.hpp"

int main(){
	std::cout << "creating a few vectors" << std::endl;

    std::vector<int> test(4, 35);
	std::vector<std::string> bebe;
	bebe.push_back("hello");
	bebe.push_back(" enfant ");
	bebe.push_back("chat");
	std::cout << bebe.front() ;
	std::cout << bebe.at(1) ;
	std::cout << bebe.back() << std::endl ;

	std::cout << test[0] ;
	std::cout << test[1] ;
	std::cout << test[2] ;
	std::cout << test[3] << std::endl << "print with ite" << std::endl;
	std::vector<std::string>::iterator baba = bebe.begin();
	while (baba != bebe.end()){
		std::cout << *baba;
		baba++;
	}

	std::cout << "\n insert:" << std::endl ;
	std::vector<std::string>::iterator bubu = bebe.insert(bebe.begin(), " coucou");
	std::cout << *bubu;
	baba = bebe.begin();
	while (baba != bebe.end()){
		std::cout << *baba;
		baba++;
	}

	std::cout << std::endl ;
	std::vector<int> test2(test);
		std::cout << test2[0] ;
	std::cout << test2[1] ;
	std::cout << test2[2] ;
	std::cout << test2[3] ;
 
	std::vector<int> test4(test2.begin(), test2.end());
		std::cout << "vector" << test4[0] ;
	std::cout << test4[1] ;
	std::cout << test4[2] ;
	std::cout << test4[3] ;
 
    // test.push_back(4);

	// stack<int, ft_vector<int> > lol(test2);
	// std::cout << lol.empty();
}