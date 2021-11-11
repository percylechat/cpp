#include "Karen.hpp"

int Karen::get_level(std::string level, std::string *karenlevel)
{
    int i = 0;

    while (i < 4)
    {
        if (level == karenlevel[i])
            return (i);
        i++;
    }
    return (i);
}

void Karen::complain( std::string level )
{
    std::string karenlevel[] =
    {
		"debug",
		"info",
		"warning",
		"error"
	};

    int i = Karen::get_level(level, karenlevel);
    
    switch (i)
    {
        case 0:
        {
            Karen::debug();
            return;
        }
        case 1:
        {
            Karen::info();
            return;
        }
        case 2:
        {
            Karen::warning();
            return;
        }
        case 3:
        {
            Karen::error();
            return;
        }
        case 4:
        {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            return;
        }
    }
}

void Karen::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
    Karen::info();
}

void Karen::info( void )
{
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
    Karen::warning();
}
void Karen::warning( void )
{
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.\n I’ve been coming here for years and you just started working here last month." << std::endl;
    Karen::error();
}

void Karen::error( void )
{
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}