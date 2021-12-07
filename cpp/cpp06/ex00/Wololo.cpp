#include "Wololo.hpp"

int ft_isnum(std::string s)
{
    unsigned long i = 0;
    if (s[0] == '-')
        i++;
    while (s[i])
    {
        if (s[i] > '9' || s[i] < '0')
            return 1;
        i++;
    }
    return 0;
}

Wololo::Wololo( std::string input )
{
    this->input = input;
}
Wololo::Wololo( void )
{
    this->input = "0";
}
Wololo::Wololo( const Wololo &one )
{
    this->input = one.input;
}
Wololo& Wololo::operator=( const Wololo &one )
{
    this->input = one.input;
    return (*this);
}

Wololo::~Wololo( void )
{}

void    Wololo::handle_char(char f)
{
    std::cout << "Char: ";
    if (f < 0 || f > 127 || this->novalue > 0)
        std::cout << "Impossible Conversion" << std::endl;
    else if (f < 32 || f == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << f << "'" << std::endl;
    
    std::cout << "Int: " << static_cast<int>(f) << std::endl;
    
    std::cout << "Float: ";
    if (f < FLT_MIN || f > FLT_MAX)
        std::cout << "Non displayable" << std::endl;
    else if (this->novalue > 0)
        std::cout << static_cast<float>(f) << 'f' << std::endl;
    else
        std::cout << static_cast<float>(f) << ".0f" << std::endl;
    
    std::cout << "Double: ";
    if ((f < DBL_MIN || f > DBL_MAX) && this->novalue == 0)
        std::cout << "Non displayable" << std::endl;
    else if (this->novalue > 0)
        std::cout << static_cast<double>(f) << std::endl;
    else
        std::cout << static_cast<double>(f) << ".0" << std::endl;
}


void    Wololo::handle_int(int f)
{
    std::cout << "Char: ";
    if (f < 0 || f > 127 || this->novalue > 0)
        std::cout << "Impossible Conversion" << std::endl;
    else if (f < 32 || f == 127)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
    
    std::cout << "Int: " << f << std::endl;
    
    std::cout << "Float: ";
    if (this->novalue > 0)
        std::cout << static_cast<float>(f) << 'f' << std::endl;
    else
        std::cout << static_cast<float>(f) << ".0f" << std::endl;
    
    std::cout << "Double: ";
    if (this->novalue > 0)
        std::cout << static_cast<double>(f) << std::endl;
    else
        std::cout << static_cast<double>(f) << ".0" << std::endl;
}

void    Wololo::handle_double(double f)
{
    if (f == 0)
        std::cout << "Char: Non Displayable\nInt: 0\nFloat: 0.0f\nDouble: 0.0\n";
    else
    {
        std::cout << "Char: ";
        if (f < 0 || f > 127 || this->novalue > 0)
            std::cout << "Impossible Conversion" << std::endl;
        else if (f < 32 || f == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        
        std::cout << "Int: ";
        if (f < INT_MIN || f > INT_MAX || this->novalue > 0)
            std::cout << "Impossible Conversion" << std::endl;
        else
            std::cout << static_cast<int>(f) << std::endl;
        
        std::cout << "Float: " << static_cast<float>(f) << "f" << std::endl;
        
        std::cout << "Double: " << f << std::endl;
    }
}

void    Wololo::handle_float(float f)
{
    if (f == 0)
        std::cout << "Char: Non Displayable\nInt: 0\nFloat: 0.0f\nDouble: 0.0\n";
    else
    {
        std::cout << "Char: ";
        if (f < 0 || f > 127 || this->novalue > 0)
            std::cout << "Impossible Conversion" << std::endl;
        else if (f < 32 || f == 127)
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
        
        std::cout << "Int: ";
        if (f < INT_MIN || f > INT_MAX || this->novalue > 0)
            std::cout << "Impossible Conversion" << std::endl;
        else
            std::cout << static_cast<int>(f) << std::endl;
        
        std::cout << "Float: " << f << "f" << std::endl;

        std::cout << "Double: " << static_cast<double>(f) << std::endl;
    }
}

void Wololo::convert()
{
    char *end = &input[input.length()];
    if (this->input == "nan" || this->input == "+inf" || this->input == "-inf")
        this->novalue = 2;
    else if (this->input == "nanf" || this->input == "+inff" || this->input == "-inff")
        this->novalue = 1;
    else
        this->novalue = 0;
    if (input.length() == 1 && input[0] == '0')
        std::cout << "Char: Non Displayable\nInt: 0\nFloat: 0.0f\nDouble: 0.0\n";
    else if (!ft_isnum(input) || (input[0] == '-' && !ft_isnum(&input[1])))
    {
        long test = strtoll(input.c_str(), &end , 10);
        if (test > INT_MAX || test < INT_MIN)
            std::cout << "Unauthorized value" << std::endl;
        else
            handle_int(static_cast<int>(atoi(input.c_str())));
    }
    else if ((input[input.length() - 1] == 'f' && input.length() > 1 && input.find('.') != std::string::npos) || novalue == 1)
    {
        float test = strtof(input.c_str(), NULL);
        if (errno == ERANGE)
            std::cout << "Unauthorized value" << std::endl;
        else
        {
            std::stringstream sstream;
            sstream << test;
            std::string test1 = sstream.str();
            if (test1 == "inf" || test1 == "-inf")
                this->novalue = 2;
            handle_float(static_cast<float>(test));
        }
    }
    else if (input.find('.') != std::string::npos || novalue == 2)
    {
        double test = strtod(input.c_str(), NULL);
        if (errno == ERANGE)
            std::cout << "Unauthorized value" << std::endl;
        else
             handle_double(static_cast<double>(test));
    }
    else if (input.length() == 1)
        handle_char(static_cast<char>(input[0]));
    else
        std::cout << "Unauthorized value" << std::endl;
}