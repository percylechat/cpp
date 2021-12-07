#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
    public:
        Fixed( void );
        ~Fixed( void );
        Fixed( const Fixed& );
        Fixed& operator=( const Fixed& );
        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int point_value;
        const static int bit_nbr = 8;
};

#endif