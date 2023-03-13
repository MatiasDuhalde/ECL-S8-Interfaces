#include "DamierDame.h"

namespace damier {

DamierDame::DamierDame() : DamierExc(10, 10, 2) {
  initJeu();

}  // namespace damier

void DamierDame::initJeu() {
  for (int l = 0; l < 4; l++)
    for (int c = 1 - l % 2; c < 10; c += 2) Set(l, c, 1);

  for (int l = 6; l < 10; l++)
    for (int c = 1 - l % 2; c < 10; c += 2) Set(l, c, 2);
}

}  // namespace damier
