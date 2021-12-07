#include "span.hpp"

std::vector<int> generator(int n)
{
    std::vector<int> myvector;
    int i = 0;
    while (i < n){
        myvector.push_back(rand() % (n * 2));
        i++;
    }
    return (myvector);
}

int main()
{
    Span test1 = Span(5);
    test1.addNumber(5);
    test1.addNumber(3);
    test1.addNumber(17);
    test1.addNumber(9);
    test1.addNumber(11);
    std::cout << test1.shortestSpan() << std::endl;
    std::cout << test1.longestSpan() << std::endl;
std::cout << "____________________" << std::endl;
    Span test2 = Span(10000);
    std::vector<int> itt = generator(10000);
    
        test2.addRange(itt.begin(), itt.end());
        std::cout << test2.shortestSpan() << std::endl;
    std::cout << test2.longestSpan() << std::endl;
    std::cout << "____________________" << std::endl;
    Span test3 = Span(10000000);
    std::vector<int> it = generator(10000000);
    
        test3.addRange(it.begin(), it.end());
        std::cout << test3.shortestSpan() << std::endl;
    std::cout << test3.longestSpan() << std::endl;
}