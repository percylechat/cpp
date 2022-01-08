#include <iostream>
#include <string>
#include "vector.hpp"
// #include "vector_iterator.hpp"
// #include <stdlib.h>
#include <vector>
// #include "stack.hpp"

int main(){

const int start_size = 7;
	ft::vector<int> vct(start_size, 20);

	ft::vector<int>::iterator it = vct.begin();

	for (int i = 2; i < start_size; ++i)
		it[i] = (start_size - i) * 3;
	
	std::cout << vct.size() << std::endl;
ft::vector<int>::iterator b = vct.begin();
while (b != vct.end()){
	std::cout << *b << std::endl;
	b++;
}
std::cout << "TEST3" << std::endl;
	vct.resize(10, 42);
	std::cout << vct.size() << std::endl;
ft::vector<int>::iterator c = vct.begin();
while (c != vct.end()){
	std::cout << *c << std::endl;
	c++;
}



	// std::cout << "creating a few vectors" << std::endl;

    // ft::vector<int> test(4, 35);
	// ft::vector<std::string> bebe;
	// bebe.push_back("hello");
	// bebe.push_back(" enfant ");
	// bebe.push_back("chat");
	// std::cout << bebe.front() ;
	// std::cout << bebe.at(1) ;
	// std::cout << bebe.back() << std::endl ;

	// std::cout << test[0] ;
	// std::cout << test[1] ;
	// std::cout << test[2] ;
	// std::cout << test[3] << std::endl << "print with ite" << std::endl;
	// ft::vector<std::string>::iterator baba = bebe.begin();
	// while (baba != bebe.end()){
	// 	std::cout << *baba;
	// 	baba++;
	// }

// 	std::cout << "\n insert deb:" << std::endl ;
// 	ft::vector<std::string>::iterator baabaa = bebe.insert(bebe.begin(), "lol ");
// 		std::cout << *baabaa << "\n" ;
// 	std::cout << "\n insert end:" << std::endl ;
// 	ft::vector<std::string>::iterator bubu = bebe.insert(bebe.end(), " coucou");
// 	std::cout << *bubu ;
// 	std::cout << "\n insert mult center:" << std::endl ;
// 	bebe.insert(bebe.begin() + 2, 4, "doudou ");
// 	std::cout << "\n insert mult center with iterator:" << std::endl ;
// 		ft::vector<std::string> vivi;
// 		vivi.push_back("percy ");
// 		vivi.push_back("kero ");
// 		vivi.push_back("Ivitch ");
// 	bebe.insert(bebe.begin() + 4, vivi.begin(), vivi.end());

// 	ft::vector<std::string>::iterator buubuu = bebe.begin();
// 	std::cout << "check\n";
// 	while (buubuu != bebe.end()){
// 		std::cout << *buubuu;
// 		buubuu++;
// 	}

// 	std::cout << "\n erase:" << std::endl ;
// 	ft::vector<std::string>::iterator bvbv = bebe.erase(bebe.begin() + 2, bebe.begin() + 4);

// 	ft::vector<std::string>::iterator buuubuuu = bebe.begin();
// 	std::cout << "check\n";
// 	while (buuubuuu != bebe.end()){
// 		std::cout << *buuubuuu;
// 		buuubuuu++;
// 	}

// 	std::cout << "\n pop back:" << std::endl ;
// 	bebe.pop_back();
// 		ft::vector<std::string>::iterator buuuubuuu = bebe.begin();
// 	std::cout << "check\n";
// 	while (buuuubuuu != bebe.end()){
// 		std::cout << *buuuubuuu;
// 		buuuubuuu++;
// 	}

// //SWAP ASSIGN RESIZE

// 	std::cout << std::endl ;
// 	ft::vector<int> test2(test);
// 		std::cout << test2[0] ;
// 	std::cout << test2[1] ;
// 	std::cout << test2[2] ;
// 	std::cout << test2[3] ;


// std::vector<int> test3;
// 	std::cout << "my size: " << test2.max_size() << std::endl;
// 	std::cout << "normal size: " << test3.max_size() << std::endl;

// 	std::vector<std::string> bibi;
// 	std::cout << "my size: " << bebe.max_size() << std::endl;
// 	std::cout << "normal size: " << bibi.max_size() << std::endl;
 
// 	ft::vector<int> test4(test2.begin(), test2.end());
// 		std::cout << "vector" << test4[0] ;
// 	std::cout << test4[1] ;
// 	std::cout << test4[2] ;
// 	std::cout << test4[3] ;
 
    // test.push_back(4);

	// stack<int, ft_vector<int> > lol(test2);
	// std::cout << lol.empty();
}