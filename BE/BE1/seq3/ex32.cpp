/********************************************************
 * Exemple 3.2 : Calcul du maximum d'une série d'entiers *
 * quelconques entres au clavier                         *
 *********************************************************/

#include <iostream>

using namespace std;

int main() {
  int maxi, i;
  cout << "Entrez une serie d'entiers quelconques au clavier" << endl;
  cout << "tapez CTRL_Z suivi de <Entree> pour terminer" << endl;
  cin >> maxi;
  while (cin) {
    cin >> i;
    if (cin) {
      if (i > maxi) maxi = i;
      cout << "max provisoire : " << maxi << endl;
    }
  }
  cout << "Valeur du maximum : " << maxi << endl;
  return 0;
}

/* Questions à se poser :
 * 1. Lorsque l’on tape CTRL_Z lors de l’exécution de l’instruction cin>>i; que
 * se passe-t-il pour i ?
 *
 * Le programme s’arrête (avec CTLR_C).
 *
 * 2. Pourquoi fait-on le test if(cin) ?
 *
 * On veut vérifier que l'input ne soit pas vide.
 *
 */
