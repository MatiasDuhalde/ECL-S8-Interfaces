#include "DamierDyn.cpp"

int main() {
  damier::DamierDyn D1(4, 5);
  D1.Init(7);
  D1.Set(2, 4, -2);
  damier::DamierDyn D2(D1);
  D1.Redim(6, 2);
  D2 = D1;

  damier::DamierDyn* D3 = new damier::DamierDyn(10, 10, 10);
  D3->Print();
  delete D3;
}
