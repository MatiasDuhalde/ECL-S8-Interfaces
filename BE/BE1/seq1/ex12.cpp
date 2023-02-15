/************************************************************
 *  Exemple 1.2 : Resolution d'une equation du second degre  *
 *************************************************************/

#include <cmath>     // déclarations des fonctions math
#include <iostream>  // déclarations des fonctions d'E/S

using namespace std;

int main()  // fonction principale (main)
{
  int a, b, c;           // variables entières locales a la fonction main
  double delta, x1, x2;  // variables réelles locales à la fonction main
  cout << "Entrez les coefficients" << endl;
  cout << "a : ";
  cin >> a;
  cout << "b : ";
  cin >> b;
  cout << "c : ";
  cin >> c;
  delta = b * b - 4 * a * c;
  if (delta < 0)
    cout << "pas de racines reelles" << endl;
  else if (delta > 0) {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
  } else {
    x1 = x2 = -b / (2 * a);
    cout << "racine double x1 = x2 = " << x1 << endl;
  }
  return 0;
}

/* Questions à se poser :
 * 1. Pourquoi faut-il des parenthèses après main alors qu'il n'y a pas
 * d'arguments ?
 *
 * Les définitions des fonctions doivent forcement inclure les parenthèses, même
 * s'il n'y a pas d'arguments.
 *
 * 2. Pourquoi y a-t-il des {} dans l'instruction if ?
 *
 * Les instructions if peuvent contenir plusieurs sous-instructions. Ces
 * sous-instructions sont regroupées entre accolades.
 *
 * 3. Pourquoi utilise-t-on les directives #include <iostream>, #include <cmath>
 * ?
 *
 * Les directives #include permettent d'inclure des fichiers de définitions de
 * la bibliothèque standard. Les fichiers iostream et cmath contiennent les
 * définitions des fonctions d'entrée/sortie et des fonctions mathématiques.
 *
 * 4.Que faudrait il changer dans le programme si l'on enlevait using namespace
 * std; ?
 *
 * Il faudrait indiquer std:: devant les fonctions qui sont définies dans ce
 * namespace. Dans ce cas, il faudrait remplacer cout par std::cout, cin par
 * std::cin, sqrt par std::sqrt et endl par std::endl.
 *
 */