/*
 ******************************************************************
 * Exemple 4.2 : Entrée d'entiers positifs au clavier et stockage *
 * dans un vecteur vide au depart. Agrandissement du vecteur a    *
 * chaque ajout                                                   *
 ******************************************************************
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int x = 1, i;
  vector<int> t;  // vecteur vide
  while (x > 0) {
    cout << "Valeur suivante : ";
    cin >> x;
    if (x > 0) t.push_back(x);  // agrandissement et stockage
  }
  cout << "Contenu du vecteur : ";
  for (i = 0; i < t.size(); i++) cout << t[i] << " ";
  cout << endl;
  return 0;
}

/* Questions à se poser :
 * 1. Que signifie l’instruction vector<int> v;, quelle est la taille de v ?
 *
 * On crée un vecteur vide. La taille n'est pas définie, donc par défaut elle
 * est de 0.
 *
 * 2. Que signifie t.push_back(x); ?
 *
 * On ajoute x à la fin du vecteur t.
 *
 * 3. Quelle est la valeur de v.size() au début, puis à la fin du programme ?
 *
 * Au début, v.size() est égal à 0. A la fin, v.size() est égal à la quantité
 * d'éléments que l'on a ajouté.
 *
 */
