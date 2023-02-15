/***********************************************************
 * Exemple 2.1 : Table de conversion fahrenheit --> celsius *
 * de 0 a 100 degres fahrenheit par pas de 20 degres        *
 ************************************************************/
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int inf = 0, sup = 100, pas = 20;
  double fahr, celsius;
  cout << "Table de conversion fahrenheit -> celsius" << endl;
  cout << "-----------------------------------------" << endl << endl;

  // ----  1ere methode : boucle while     ----
  fahr = inf;
  while (fahr <= sup) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    cout << "En fahrenheit : " << fahr;
    cout << " -  En celsius : " << celsius << endl;
    fahr = fahr + pas;
  }

  // ----  2eme methode : boucle  dowhile  ----
  cout << endl;
  fahr = inf;
  do {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    cout << "En fahrenheit : " << fahr;
    cout << " -  En celsius : " << celsius << endl;
    fahr = fahr + pas;
  } while (fahr <= sup);

  // ----  3eme methode : boucle  for      ----
  cout << endl;
  for (fahr = inf; fahr <= sup; fahr = fahr + pas) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    cout << "En fahrenheit : " << fahr;
    cout << " -  En celsius : " << celsius << endl;
  }

  // ----  4eme methode : boucle  for ameliore ----
  cout << fixed;
  cout.precision(2);
  for (fahr = inf; fahr <= sup; fahr = fahr + pas) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    cout << "En fahrenheit : " << setw(10) << fahr;
    cout << " -  En celsius : " << setw(6) << celsius << endl;
  }
  return 0;
}

/* Questions à se poser :
 * 1. A quoi sert le setw(6) dans cout<<setw(6)<<x; ? Quelle est la durée de
 * l’effet de la commande ?
 *
 * setw(6) permet de définir la largeur du champ de sortie à 6 caractères. La
 * durée de l’effet de la commande est seulement pour l'élément suivant.
 *
 * 2. A quoi sert cout<<fixed; ? Quelle est la durée d’effet de cette commande ?
 *
 * fixed sert à représenter toujours un float un point décimal. La durée d'effet
 * de cette commande est jusqu'au fin du programme.
 *
 * 3. A quoi sert cout.precision(2); ? Quelle est la durée de l’effet de la
 * commande ?
 *
 * cout.precision(2) permet de définir le nombre de chiffres après la virgule
 * à 2. La durée d'effet de cette commande est jusqu'au fin du programme.
 *
 * 4. Pourquoi utilise-t-on la directive #include <iomanip> ?
 *
 * Pour utiliser les fonctions de la bibliothèque iomanip. Dans ce cas, on
 * utilise setw, qui appartiennent à la bibliothèque iomanip.
 */