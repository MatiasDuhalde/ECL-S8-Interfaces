/*************************************************************
 * Programme à réaliser
 *
 * - En utilisant les pointeurs et l’allocation dynamique, écrire un programme
 * qui demande à l’utilisateur la taille n d’un tableau d’entier t,
 * - Remplit le tableau avec n valeurs saisies au clavier par l’utilisateur,
 * - Affiche le tableau t,
 * - Trie les données de t par ordre croissant (tri par bulles) à l’aide de
 * pointeurs,
 * - Affiche le tableau t trié.
 **************************************************************/

#include <iostream>

using namespace std;

int main() {
  int *p1, *p2;
  int x, i, n, *t, n2;

  cout << "Donner la taille du tableau: ";
  cin >> n;
  t = new int[n];
  for (int i = 0; i < n; i++) {
    cout << "Donner la valeur de t[" << i << "]: ";
    cin >> t[i];
  }

  cout << "Valeurs du tableau :" << endl;
  for (int i = 0; i < n; i++) cout << t[i] << " ";
  cout << endl;

  // Tri par bulles
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (t[j] > t[j + 1]) {
        swap(t[j], t[j + 1]);
      }
    }
  }

  cout << "Valeurs du tableau trie :" << endl;
  for (int i = 0; i < n; i++) cout << t[i] << " ";
  cout << endl;

  return 0;
}
