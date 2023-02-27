#include "DamierDyn.h"

int main() {
  damier::DamierDyn D1(5, 5, 3);
  damier::DamierDyn D2(5, 5, 8);
  // test de l'opérateur + et <<
  damier::DamierDyn D3 = D1 + D2;
  std::cout << D3 << std::endl;
  // test de l'opérateur +=
  D3 += D1;
  std::cout << D3 << std::endl;

  // test de l'opérateur =
  D1.Redim(3, 3);
  std::cout << D1 << std::endl;

  D3 = D1;
  std::cout << D3 << std::endl;

  return 0;
}
