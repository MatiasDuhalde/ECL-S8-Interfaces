/********************************************************
 * Programme à réaliser
 *
 * - Écrire un programme qui lit une série d’entiers quelconques (positifs,
 * négatifs ou nuls) au clavier. On ne connaît pas a priori la longueur de la
 * série, c’est l’utilisateur qui décide d’arrêter de fournir des entiers en
 * envoyant le signal fin de fichier. On calcule la somme, la moyenne et la
 * variance.
 * $$variance = \frac{\sum_{i=1}^{N}{(x_i - moyenne)^2}}{N}$$
 *********************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x;
  vector<int> t;

  while (cin) {
    cout << "Valeur suivante : ";
    cin >> x;
    t.push_back(x);
  }

  int somme = 0;
  for (int i = 0; i < t.size(); i++) somme += t[i];
  float moyenne = somme / t.size();
  float variance = 0;
  for (int i = 0; i < t.size(); i++)
    variance += (t[i] - moyenne) * (t[i] - moyenne);
  variance /= t.size();

  cout << "Somme : " << somme << endl;
  cout << "Moyenne : " << moyenne << endl;
  cout << "Variance : " << variance << endl;

  return 0;
}
