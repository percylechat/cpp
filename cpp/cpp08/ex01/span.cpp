#include "span.hpp"

Span::Span()
{
    tot = 0;
    index = 0;
    stock[0];
}

Span::Span(unsigned int n)
{
    tot = n;
    index = 0;
    stock[n];
}

Span::Span(const Span &one)
{
    tot = one.tot;
    stock[tot];
    if (one.index != 0)
    {
        int j = 0;
        while (j < one.index)
        {
            stock[j] = one.stock[j];
            j++;
        }
    }
    index = one.index;
}

Span& Span::operator=( const Span &one )
{
    tot = one.tot;
    stock[tot];
    if (one.index != 0)
    {
        int j = 0;
        while (j < one.index)
        {
            stock[j] = one.stock[j];
            j++;
        }
    }
    index = one.index;
    return *this;
}

Span::~Span(){}

void Span::addRange(std::vector<int>::iterator deb, std::vector<int>::iterator end)
{
    while (deb != end){
        try {
            // std::cout << *deb << " ";
            this->addNumber(*deb); deb++;
        }
        catch (std::exception &e){
            std::cerr << e.what() << std::endl; return;
        }
    }
}

void Span::addRange(int *i, int k)
{
    int j = 0;
    while (j < k)
    {
        try {this->addNumber(i[j]); j++;}
        catch (std::exception &e){std::cerr << e.what() << std::endl; return;}
    }
}

void Span::addNumber(int n)
{
    if (index < tot)
    {
        stock.push_back(n);
        index++;
    }
    else
        throw std::overflow_error("Already full");
}

int Span::shortestSpan()
{
    int save = longestSpan();

    std::vector<int> buf(tot);
    std::copy (stock.begin(), stock.end(), buf.begin());
    std::sort (buf.begin(), buf.end());
    int j = 0;
    while (j + 1 < index)
    {
        save = std::min(save, buf[j + 1] - buf[j]);
        j++;
    }
    return (save);
}

int Span::longestSpan(){return *std::max_element(stock.begin( ),stock.end()) - *std::min_element(stock.begin( ),stock.end());}