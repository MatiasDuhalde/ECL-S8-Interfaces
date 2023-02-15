/******************************************************************
 * Exemple 4.1 : Entrée d'une série d'entiers positifs au clavier  *
 * et stockage dans un vecteur a taille prédéfinie                 *
 *******************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int nb = 0, x = 1, i;
  vector<int> v(100);  // vecteur de taille 100
  while (x > 0) {
    cout << "Valeur suivante : ";
    cin >> x;
    if (x > 0) {
      v[nb] = x;
      nb++;
    }
  }
  cout << "Contenu du vecteur : ";
  for (i = 0; i < nb; i++) cout << v[i] << " ";
  cout << endl;
  cout << "Taille du vecteur : " << v.size() << endl;
  cout << "Place occupee : " << nb << endl;
  return 0;
}

/* Questions à se poser :
 * 1. Que signifie l’instruction vector<int> v(100); ?
 *
 * On crée un vecteur de taille 100.
 *
 * 2. Que vaut ici v.size(), est-il différent de nb ?
 *
 * v.size() est égal à 100, et nb est égal à la place occupée dans le vecteur.
 *
 */
