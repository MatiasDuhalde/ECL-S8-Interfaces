#include "DamierStat.h"

int main() {
  damier::DamierStat D1;  // Création du Damier et initialisation des cases à 0
  D1.Init(7);             // Initialisation de toutes les cases à 7
  D1.Set(2, 4, -2);       // Modification de la case (2, 4) avec la valeur -2
  D1.Print();             // Affichage du tableau

  damier::DamierStat* D2 = new damier::DamierStat();
  delete D2;
}
