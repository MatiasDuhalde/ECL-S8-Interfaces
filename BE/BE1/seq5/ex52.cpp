/********************************************************
 * Programme à réaliser
 *
 * - Reprendre le programme réalisé à la séquence 4, mais cette fois-ci, le
 * calcul de la moyenne et de la variance sera écrit au sein d’une fonction
 * prenant trois arguments :
 *    - le vecteur d’entier,
 *    - la moyenne calculée,
 *    - la variance calculée.
 * - Écrire deux variantes de cette fonction :
 *    - statistique_p : en utilisant un passage d’arguments par adresse
 *    (pointeurs)
 *    - statistique_r : en utilisant un passage d’arguments par référence
 *********************************************************/

#include <iostream>
#include <vector>

using namespace std;

void statistique_p(vector<int>* t, float* moyenne, float* variance) {
  float somme = 0;
  for (int i = 0; i < t->size(); i++) somme += t->at(i);
  *moyenne = somme / t->size();
  *variance = 0;
  for (int i = 0; i < t->size(); i++)
    *variance += (t->at(i) - *moyenne) * (t->at(i) - *moyenne);
  *variance /= t->size();
}

void statistique_r(vector<int>& t, float& moyenne, float& variance) {
  float somme = 0;
  for (int i = 0; i < t.size(); i++) somme += t[i];
  moyenne = somme / t.size();
  variance = 0;
  for (int i = 0; i < t.size(); i++)
    variance += (t[i] - moyenne) * (t[i] - moyenne);
  variance /= t.size();
}

int main() {
  int x;
  vector<int> t;

  while (cin) {
    cout << "Valeur suivante : ";
    cin >> x;
    t.push_back(x);
  }

  float moyenne_1, variance_1, moyenne_2, variance_2;

  statistique_p(&t, &moyenne_1, &variance_1);
  statistique_r(t, moyenne_2, variance_2);

  cout << "Moyenne 1 : " << moyenne_1 << endl;
  cout << "Variance 1 : " << variance_1 << endl;

  cout << "Moyenne 2 : " << moyenne_2 << endl;
  cout << "Variance 2 : " << variance_2 << endl;

  return 0;
}
