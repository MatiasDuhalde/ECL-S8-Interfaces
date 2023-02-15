/********************************************************
 * Exemple 3.1 : Calcul du maximum d'une serie d'entiers *
 * positifs entres au clavier                            *
 **********************************************************/

#include <iostream>

using namespace std;

int main() {
  int maxi = -1, i = 1;
  cout << "Entrez une serie d'entiers positifs" << endl;
  cout << "tapez 0 pour terminer" << endl;
  while (i > 0) {
    cin >> i;
    if (i > maxi) maxi = i;
    cout << "max provisoire : " << maxi << endl;
  }
  cout << "Valeur du maximum : " << maxi << endl;
  return 0;
}