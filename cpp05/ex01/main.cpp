// Fichiers à rendre : Bureaucrat.hpp Bureaucrat.cpp main.cpp
// Fonctions interdites : Aucune
// Notez bien que les classes d’exceptions ne doivent pas être sous forme coplienne. Le
// reste des classes doit bien l’être.
// Aujourd’hui, nous allons créer un cauchemar artificiel de bureaux, couloirs, Forms, et
// lignes d’attente.
// Ca a l’air fun, hein ? Non ? Dommage.
// Premièrement, nous allons placer le plus petit engrenage dans la vaste machine bureau-
// cratique moderne. Le Bureaucrat.
// Il doit avoir un nom (constant), et un grade, qui va de 1 (le plus haut) à 150 (le
// plus bas). Toute tentative de créer un Bureaucrat avec un grade invalide doit en-
// voyer une exception qui sera soit une Bureaucrat::GradeTooHighException ou une
// Bureaucrat::GradeTooLowException.
// Vous créerez aussi des getters pour ces deux attributs (getName et getGrade), et deux
// fonctions pour incrémenter/décrémenter le grade. Attention : le grade 1 est le plus haut,
// donc le décrémenter vous donnera un grade 2, etc...
// Les exceptions doivent être attrapables par un bloc de code du type :
// try
// {
/* do some stuff with bureaucrats */
// }
// catch (std::exception & e)
// {
/* handle exception */
// }
// Vous devez également overloader l’opérateur « qui affichera quelque chose du genre :
// <name>, bureaucrat grade <grade>.
// Bien entendu, vous rendrez un main pour prouver que tout fonctionne.

// #include "Bureaucrat.hpp"

// int main(void) {

// 	Bureaucrat player1("player1", 1);
// 	Bureaucrat player2("player2", 150);
// 	Form certificate("CPP05", 50, 50);

// 	std::cout << "===========================================\n";

// 	std::cout << certificate;

// 	std::cout << "===========================================\n";

// 	try {
// 		player2.signForm(certificate);
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	try {
// 		player1.signForm(certificate);
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << "===========================================\n";

// 	std::cout << certificate;

// 	std::cout << "===========================================\n";
// }

// #include "Bureaucrat.hpp"
// int main()
// {
//     Bureaucrat i("John", 12);
//     Bureaucrat j;
//     j = Bureaucrat(i);
//     std::cout << j.getName();
//     // try
//     // {
//     //     // Bureaucrat i("John", 160);
//     // }
//     // catch (Bureaucrat::GradeTooLowException & e)
//     // {
//     //     std::cerr << e.error_low() << std::endl;
//     // }
// }