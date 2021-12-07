#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstdlib>

class Span
{
    private:
        std::vector<int> stock;
        int index;
        int tot;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &);
        Span& operator=( const Span &one );
        ~Span();
        void addNumber(int n);
        void addRange(int *i, int k);
        void addRange(std::vector<int>::iterator deb, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};

#endif