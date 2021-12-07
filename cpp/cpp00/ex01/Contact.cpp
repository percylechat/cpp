#include <string.h>
#include <iostream>
#include "./Contact.hpp"
#include "./Phonebook.hpp"

void Contact::create_contact( )
{
    std::string input;

    std::cout << "First name" << std::endl;
    std::getline(std::cin >> std::ws, input);
    this->set_fn(input);
    std::cout << "Last name" << std::endl;
    std::getline(std::cin >> std::ws, input);
    this->set_ln(input);
    std::cout << "Nickname" << std::endl;
    std::getline(std::cin >> std::ws, input);
    this->set_nn(input);
    std::cout << "Phone number" << std::endl;
    std::getline(std::cin >> std::ws, input);
    this->set_pn(input);
    std::cout << "Darkest secret" << std::endl;
    std::getline(std::cin >> std::ws, input);
    this->set_s(input);
    return ;
}

std::string Contact::check_size(std::string str)
{
    int i;
    std::string repl;

    i = str.length();
    if (i < 11)
        return (str);
    else
    {
        repl.append(str, 0, 9);
        repl+=".";
        return (repl);
    }
}

void Contact::set_fn(std::string str)
{
    this->first_name = str;
}

void Contact::set_ln(std::string str)
{
    this->last_name = str;
}

void Contact::set_nn(std::string str)
{
    this->nickname = str;
}

void Contact::set_pn(std::string str)
{
    this->phone_number = str;
}

void Contact::set_s(std::string str)
{
    this->secret = str;
}

std::string Contact::get_fn()
{
    return this->first_name;
}

std::string Contact::get_ln()
{
    return this->last_name;
}

std::string Contact::get_nn()
{
    return this->nickname;
}

std::string Contact::get_pn()
{
    return this->phone_number;
}

std::string Contact::get_s()
{
    return this->secret;
}