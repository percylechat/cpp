#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed( void );
        Fixed( const int );
        Fixed(const float );
        Fixed( const Fixed& );
        Fixed& operator=( const Fixed& );
        ~Fixed( void );
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int point_value;
        const static int bit_nbr = 8;
};

std::ostream& operator<<( std::ostream&, const Fixed& );

#endif