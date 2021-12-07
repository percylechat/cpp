#ifndef KAREN_H
#define KAREN_H

#include <iostream>

class Karen
{
    public:
    void complain( std::string level );
    int get_level( std::string level, std::string *karenlevel );
    private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
};

#endif