#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

// Container c
// 	the underlying container
// (protected member object)

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack<T>& one) {
            *this = one;
        }
        ~MutantStack() {}
        MutantStack<T>& operator=(const MutantStack<T>& one) {
            this->c = one.c;
            return *this;
        }
        typedef typename MutantStack<T>::container_type::iterator iterator;
        iterator begin() {
            return std::stack<T>::c.begin();
        }
        iterator end(){
            return std::stack<T>::c.end();
        }
};

#endif // !MUTANTSTACK_HPP