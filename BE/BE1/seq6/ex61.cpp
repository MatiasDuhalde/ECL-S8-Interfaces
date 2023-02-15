/*************************************************************
 * Exemple 6.1 : Elimination des occurrences d'une valeur     *
 * dans un tableau alloué dynamiquement et géré               *
 * avec des pointeurs                                         *
 **************************************************************/

#include <iostream>

using namespace std;

int main() {
  int *p1, *p2;
  int x, i, n, *t, n2;

  cout << "Donner la dimension du tableau: ";
  cin >> n;
  t = new int[n];  // Allocation dynamique d'un tableau à n valeurs entières
  for (int i = 0; i < n; i++) {
    cout << "Donner la valeur de t[" << i << "]: ";
    cin >> t[i];
  }

  cout << "Valeurs du tableau :" << endl;
  for (int i = 0; i < n; i++) {
    cout << "t[" << i << "] = " << t[i] << endl;
  }

  cout << "Donner la valeur de l'element a supprimer : ";
  cin >> x;

  for (n2 = 0, p1 = p2 = t; p1 < t + n; p1++) {
    if (*p1 != x) {
      *p2 = *p1;
      p2++;
      n2++;
    }
  }
  cout << "Nouvelles valeurs du tableau :" << endl;
  for (i = 0, p1 = t; p1 < t + n2; p1++, i++) {
    cout << "t[" << i << "] = " << *p1 << endl;
  }

  return 0;
}
