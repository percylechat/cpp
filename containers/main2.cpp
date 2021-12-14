#include <iostream>
#include <string>
#include "vectorbis.hpp"
// #include "iterator_vector.hpp"
#include <stdlib.h>
#include <vector>

int main(){
	std::cout << "creating a few vectors" << std::endl;

// ft_vector<int> first;                                // empty vector of ints
// ft_vector<int> second (4,100);                       // four ints with value 100
// ft_vector<int> third (second.begin(),second.end());  // iterating through second
// ft_vector<int> fourth (third);                       // a copy of third

// //   // the iterator constructor can also be used to construct from arrays:
// int myints[] = {16,2,77,29};
// ft_vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft_vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it << '\n';

//   return 0;	




    ft_vector<int> test(4, 35);
	ft_vector<std::string> bebe;
	bebe.push_back("hello");
	bebe.push_back(" enfant ");
	bebe.push_back("chat");
	std::cout << bebe.front() ;
	std::cout << bebe.at(1) ;
	std::cout << bebe.back() << std::endl ;

	std::cout << test[0] ;
	std::cout << test[1] ;
	std::cout << test[2] ;
	std::cout << test[3] ;
		std::cout << std::endl ;
	ft_vector<std::string>::iterator baba = bebe.begin();
	while (baba != bebe.end()){
		std::cout << *baba;
		baba++;
	}

	std::cout << std::endl ;
	bebe.insert(bebe.end(), " coucou");
	baba = bebe.begin();
	while (baba != bebe.end()){
		std::cout << *baba;
		baba++;
	}

	std::cout << std::endl ;
	ft_vector<int> test2(test);
		std::cout << test2[0] ;
	std::cout << test2[1] ;
	std::cout << test2[2] ;
	std::cout << test2[3] ;


std::vector<int> test3;
	std::cout << "my size: " << test2.max_size() << std::endl;
	std::cout << "normal size: " << test3.max_size() << std::endl;

	std::vector<std::string> bibi;
	std::cout << "my size: " << bebe.max_size() << std::endl;
	std::cout << "normal size: " << bibi.max_size() << std::endl;
    // test.push_back(4);


}