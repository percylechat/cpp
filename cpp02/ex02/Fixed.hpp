#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

// •Six opérateurs de comparaison : >, <, >=, <=, == and !=.
// •Quatre opérateurs arithmétiques : +, -, *, et /.
// •Les opérateurs de pre-incrément, post-incrément, pré-décrément et post-décrément,
// qui vont incrémenter et décrémenter la valeur du nombre à point fixe de la valeur
// représentable lapluspetitetelleque1 + nbr > 1.
// Ajoutez les overloads de fonctions membres statiques publiques à votre classe :
// •La fonction membre statique min qui prend une référence sur deux nombres a point
// fixe et qui renvoie une réference vers le plus petit, et un overload qui prend deux
// references sur deux nombres à point fixe et qui renvoie une réference vers la plus
// petite valeur.
// •La fonction membre statique max qui prend une référence sur deux nombres à point
// fixe et qui renvoie une réference vers le plus grand, et un overload qui prend une
// reférence sur deux nombres à point fixe et qui renvoie une réference vers la plus
// grande valeur.

class Fixed
{
    public:
        Fixed( void );
        Fixed ( const int );
        Fixed (const float );
        Fixed( const Fixed& );
        Fixed& operator=( const Fixed& );
        int operator<( const Fixed& );
        int operator>( const Fixed& );
        int operator>=( const Fixed& );
        int operator<=( const Fixed& );
        int operator!=( const Fixed& );
        int operator==( const Fixed& );
        Fixed operator+( const Fixed& );
        Fixed operator-( const Fixed& );
        Fixed operator*( const Fixed& );
        Fixed operator/( const Fixed& );
        Fixed& operator++( void );
        Fixed& operator--( void );
        Fixed operator++( int );
        Fixed operator--( int );
        static Fixed &max( Fixed&, Fixed& );
        static const Fixed &max(const Fixed &, const Fixed &);
        static Fixed &min( Fixed&, Fixed& );
        static const Fixed &min(const Fixed &, const Fixed &);
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