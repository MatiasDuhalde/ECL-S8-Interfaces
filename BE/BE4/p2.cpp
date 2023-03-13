#include "DamierExc.h"

int main() {
  damier::DamierExc D(3, 5, 4);  // damier de dimensions (3,5) et de borne 4
  D.Set(1, 2, 3);                // pas de levée d'exception

  try {
    D.Init(6);  // levée d'exception car 6 n'est pas dans [0, 3]

  } catch (damier::ExceptionDamier& e) {
    std::cout << "Exception:" << std::endl;
    std::cout << e.what() << std::endl;
  }

  return 0;
}
