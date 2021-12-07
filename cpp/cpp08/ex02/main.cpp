#include "mutantstack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "______________" << std::endl;

    MutantStack<int> msitack;

    int i = 0;
    while ( i < 10) 
    {
        msitack.push(rand());
        std::cout << msitack.top() << std::endl;
        i++;
    }
    i = 0;
        std::cout << "_" << std::endl;
    MutantStack<int>::iterator iit = msitack.begin();
    MutantStack<int>::iterator iite = msitack.end();
    ++iit;
    --iit;
    while (iit != iite)
    {
        std::cout << *iit << std::endl;
        ++iit;
    }
}