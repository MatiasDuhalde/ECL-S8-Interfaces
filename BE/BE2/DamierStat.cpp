#include "DamierStat.h"

namespace damier {

DamierStat::DamierStat() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++) tableau[i][j] = 0;
}

void DamierStat::Init(int val) {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 5; j++) tableau[i][j] = val;
}

void DamierStat::Set(int i, int j, int val) { tableau[i][j] = val; }

void DamierStat::Print() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 5; j++) std::cout << tableau[i][j] << " ";
    std::cout << std::endl;
  }
}

}  // namespace damier
