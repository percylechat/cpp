#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>

class Phonebook;

class Contact
{
    public:
        void create_contact( );
        std::string check_size( std::string str );
        void set_fn( std::string );
        void set_ln( std::string );
        void set_nn( std::string );
        void set_pn( std::string );
        void set_s( std::string );
        std::string get_fn( void );
        std::string get_ln( void );
        std::string get_nn( void );
        std::string get_pn( void );
        std::string get_s( void );
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;

};

#endif