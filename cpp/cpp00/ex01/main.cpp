#include <string.h>
#include <iostream>
#include "./Contact.hpp"
#include "./Phonebook.hpp"

int main()
{
    std::string input;
    Phonebook book;

    book.set_n(0);
    while (1)
    {
        std::cout << "Welcome to the Phonebook! Please type ADD to create a new contact, SEARCH to see all contacts or EXIT to quit." << std::endl;
        std::cin >> input;
        if (input.compare("EXIT") == 0)
        {
            std::cout << "BYE" << std::endl;
            return (0);
        }
        else if (input.compare("ADD") == 0)
        {
            if (book.get_n() == 8)
                std::cout << "Phonebook full, sorry!" << std::endl;
            else
            {
                book.tab[book.get_n()].create_contact();
                if (book.get_n() < 8)
                    book.set_n(book.get_n() + 1);
            }
        }
        else if (input.compare("SEARCH") == 0)
        {
            if (book.get_n() == 0)
                std::cout << "The Phonebook is empty! Please add some contacts beforehand." << std::endl;
            else
            {
                book.display_phonebook();
                book.display_contact();
            }
        }
    }
    return (0);
}