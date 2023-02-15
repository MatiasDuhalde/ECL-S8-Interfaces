/******************************************************
 * Programme à réaliser
 *
 * - Écrire un programme qui lit un entier N et qui affiche à l’écran une table
 * des carres et des racines carrées de N premiers entiers.
 * - NB. On peut réaliser a^x à l’aide de multiplications, ce qui est le plus
 * rapide dans le cas ou x est entier. On peut aussi utiliser la fonction de
 * bibliothèque pow(a, x). Pour pouvoir utiliser cette fonction, il faut inclure
 * le fichier système cmath qui contient les prototypes des fonctions
 * mathématiques. La fonction pow a des arguments de type double et une valeur
 * de retour de type double.
 *******************************************************/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Entrez un nombre" << endl;
  cout << "n : ";
  cin >> n;

  cout << fixed;
  cout.precision(2);

  cout << setw(3) << "i"
       << " | " << setw(8) << "i^2"
       << " | " << setw(8) << "sqrt(i)" << endl;
  for (int i = 1; i <= n; i++)
    cout << setw(3) << i << " | " << setw(8) << (i * i) << " | " << setw(8)
         << sqrt(i) << endl;

  return 0;
}
