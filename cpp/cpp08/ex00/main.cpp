#include "easyfind.hpp"

#include <set>
#include <vector>

int main(void)
{
	std::vector<int> test1;
	int i = 0;
	while (i < 10)
	{
		test1.push_back(i);
		i++;
	}
	try
	{
		std::cout << easyfind(test1, 4) << std::endl;
	}
	catch (std::exception &e){ std::cerr << e.what() << std::endl;}

	std::set<int> test2;
	i = 0;
	while (i < 10)
	{
		test2.insert(i);
		i++;
	}
	try
	{
		std::cout << easyfind(test2, 10) << std::endl;
	}
	catch (std::exception &e){ std::cerr << e.what() << std::endl;}
	try
	{
		std::cout << easyfind(test2, 14) << std::endl;
	}
	catch (std::exception &e){ std::cerr << e.what() << std::endl;}
	return 0;
}