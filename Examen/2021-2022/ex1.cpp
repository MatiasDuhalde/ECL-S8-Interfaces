#include <iostream>

class PileIntStat {
 public:
  PileIntStat(int taille = 100);
  int get_taille();
  bool est_vide();
  void empile(int v);
  int depile();

 private:
  int tab[100];
  int top;
  int taille;
};

PileIntStat::PileIntStat(int t) {
  if (t >= 100)
    taille = 100;
  else
    taille = t;
  top = -1;
}

bool PileIntStat::est_vide() { return top == -1; }

void PileIntStat::empile(int v) {
  top++;
  tab[top] = v;
}

int PileIntStat::depile() {
  int v = tab[top];
  top--;
  return v;
}

int PileIntStat::get_taille() { return taille; }

int main() {
  PileIntStat p1(10);
  std::cout << "Taille de p1: " << p1.get_taille() << std::endl;

  p1.empile(22);
  p1.empile(207);

  int v;
  while (!p1.est_vide()) {
    v = p1.depile();
    std::cout << "Valeur : " << v << std::endl;
  }
  return 0;
}