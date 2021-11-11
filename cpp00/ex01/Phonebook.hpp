#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contact.hpp"
#include <iostream>

class Phonebook
{
    public:
        Contact tab[8];
        void display_phonebook();
        void display_contact();
        int get_n();
        void set_n(int);
    private:
        int contacts;
};

#endif