/********************************************************
 * Programme à réaliser
 *
 * - Écrire un programme qui lit une série d’entiers quelconques et détermine le
 * maximum, le minimum et la valeur moyenne de la série.
 *********************************************************/

#include <climits>
#include <iostream>

using namespace std;

int main() {
  int n = 0;
  int maxi = INT_MIN;
  int mini = INT_MAX;
  int i;
  float total = 0;
  cout << "Entrez une serie d'entiers quelconques au clavier" << endl;
  cout << "tapez CTRL_Z suivi de <Entree> pour terminer" << endl;
  while (cin) {
    cin >> i;
    if (cin) {
      n++;
      total += i;
      if (i > maxi) maxi = i;
      if (i < mini) mini = i;
      cout << "max provisoire : " << maxi << endl;
      cout << "min provisoire : " << mini << endl;
      cout << "moyenne provisoire : " << total / n << endl;
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