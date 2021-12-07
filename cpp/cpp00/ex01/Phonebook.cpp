#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "./Contact.hpp"
#include "./Phonebook.hpp"

void    Phonebook::display_phonebook()
{
    int i;

    i = 0;
    std::cout << std::setw(10);
    std::cout << "index";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << "first name";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << "last name";
    std::cout << "|";
    std::cout << std::setw(10);
    std::cout << "nickname" << std::endl;
    while (i < this->get_n())
    {
        std::cout << std::setw(10);
        std::cout << i;
        std::cout << "|";
        std::cout << std::setw(10);
        std::cout << this->tab[i].check_size(this->tab[i].get_fn());
        std::cout << "|";
        std::cout << std::setw(10);
        std::cout << this->tab[i].check_size(this->tab[i].get_ln());
        std::cout << "|";
        std::cout << std::setw(10);
        std::cout << this->tab[i].check_size(this->tab[i].get_nn()) << std::endl;
        i++;
    }
}

void Phonebook::display_contact()
{
    std::string i;
    std::cout << "Type the index number you want to consult:" << std::endl;
    std::cin >> i;
    if (i.size() > 1)
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    if (i != "0" && i != "1" && i != "2" && i != "3" && i != "4" && i != "5" && i != "6" && i != "7")
    {
        std::cout << "Invalid input" << std::endl;
        return ;
    }
    int j = atoi(i.c_str());
    if (j < 0 || j > this->get_n() - 1)
    {
        std::cout << "This contact does not exist" << std::endl;
        return ;
    }
    std::cout << this->tab[j].get_fn() << std::endl;
    std::cout << this->tab[j].get_ln() << std::endl;
    std::cout << this->tab[j].get_nn() << std::endl;
    std::cout << this->tab[j].get_pn() << std::endl;
    std::cout << this->tab[j].get_s() << std::endl;
}

int Phonebook::get_n()
{
    return this->contacts;
}

void Phonebook::set_n(int n)
{
    this->contacts = n;
}