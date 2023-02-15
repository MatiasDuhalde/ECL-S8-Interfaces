/******************************************************
 *  Exemple 1.1 : Calcul de la moyenne de deux entiers *
 *******************************************************/

#include <iostream>  // déclarations des fonctions d'E/S de bibliothèque

using namespace std;  // utilisation de noms courts pour la bibliothèque

int main()  // fonction principale (main)
{
  int a, b, c;  // variables entières locales a la fonction main
  cout << "Entrez les deux nombres entiers" << endl;  // écriture
  cout << "a : ";
  cin >> a;  // écriture puis lecture
  cout << "b : ";
  cin >> b;                     // écriture puis lecture
  c = (a + b) / 2;              // calcul
  cout << "c = " << c << endl;  // écriture résultat
  return 0;
}
