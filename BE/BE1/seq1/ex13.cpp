/******************************************************
 * Programme à réaliser
 *
 * - Écrire un programme qui lit un nombre entier, détermine s’il est pair ou
 * impair et écrit sur l’écran pair ou impair.
 * - Indication : l’opérateur % donne le reste de la division entière d’un
 * entier par un autre, par exemple, l’expression 7%2 vaut 1.
 *******************************************************/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Entrez un nombre" << endl;
  cout << "n : ";
  cin >> n;
  if (n % 2 == 0)
    cout << "pair" << endl;
  else
    cout << "impair" << endl;
  return 0;
}
