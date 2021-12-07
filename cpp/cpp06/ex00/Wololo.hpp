#ifndef WOLOLO_H
#define WOLOLO_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits>
#include <string>
#include <sstream>

class Wololo
{
    private:
        std::string input;
        int novalue;
    public:
        Wololo( std::string input );
        Wololo( void );
        Wololo( const Wololo &one );
        Wololo& operator=( const Wololo & );
        ~Wololo( void );
        void convert( void );
        void handle_float(float f);
        void handle_double(double f);
        void handle_char(char f);
        void handle_int(int f);
};

#endif