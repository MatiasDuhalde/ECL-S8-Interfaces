#include "DamierDynG.cpp"

int main(int argc, char *argv[]) {
  damier::DamierDynG<float> Dfloat(2, 2, 0);

  Dfloat.Init(-1.4f);
  Dfloat += 4.5f;
  Dfloat.Set(1, 0, 13.4f);
  std::cout << Dfloat;

  return 0;
}