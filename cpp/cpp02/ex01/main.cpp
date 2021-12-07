// ; Fichiers à rendre : Makefile, main.cpp, Fixed.hpp and Fixed.cpp
// ; Fonctions Autorisées : roundf (from <cmath>)
// ; Bon, l’ex00 était un bon départ, mais notre classe ne sert littéralement à rien pour
// ; l’instant, car elle ne peut représenter que la valeur 0.0. Ajoutez donc les constructeurs
// ; et fonctions membres publiques suivantes à votre classe :
// ; •Un constructeur qui prend un const int en paramètre et qui le converti à sa valeur
// ; fixe(8) correspondante. La partie fractionnelle doit être initialisée comme dans
// ; l’ex00.
// ; •Un constructeur qui prend un const float en paramètre et et le convertit à sa
// ; valeur fixe(8) correspondante. La partie fractionnelle doit être initialisée comme
// ; dans l’ex00.
// ; •Une fonction membre float toFloat(void) const; qui convertit un nombres à
// ; point fixe en float.
// ; •Une fonction membre int toInt(void) const; qui convertit un nombres à point
// ; fixe en int.
// ; Vous ajouterez aussi l’overload suivant dans votre header et votre fichier source :
// ; •Overload de « qui insère une représentation de votre nombre à point fixe dans
// ; l’output demandé.
#include "Fixed.hpp"

#include <iostream>
int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);
    a = Fixed(1234.4321f);
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "a is " << a.toFloat() << " as float" << std::endl;
    std::cout << "b is " << b.toFloat() << " as float" << std::endl;
    std::cout << "c is " << c.toFloat() << " as float" << std::endl;
    std::cout << "d is " << d.toFloat() << " as float" << std::endl;
    return 0;
}