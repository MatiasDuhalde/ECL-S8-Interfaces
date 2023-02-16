#include <iomanip>

#include "DamierDynG.cpp"

int main(int argc, char *argv[]) {
  damier::DamierDynG<bool> Dbool(3, 4, false);
  Dbool.Init(true);
  Dbool.Set(1, 1, false);
  Dbool += false;
  damier::DamierDynG<bool> Dbool2(3, 4, false);
  Dbool2.Set(2, 2, true);

  std::cout << Dbool;
  std::cout << Dbool2;
  Dbool2 += Dbool;
  Dbool2 += Dbool;
  Dbool2 += Dbool;
  Dbool2 += Dbool;
  std::cout << Dbool2;

  return 0;
}

// 0 est faux, 1 est vrai
// l'opérateur + est défini pour les booléens
// il fonctionne comme l'opérateur || (ou logique)
