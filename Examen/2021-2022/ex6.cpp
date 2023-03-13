#include <iostream>

class PileIntStat {
 public:
  PileIntStat(int taille = 100);
  int get_taille();
  bool est_vide();
  void empile(int v);
  int depile();

  PileIntStat& operator+=(PileIntStat& D);

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

PileIntStat& PileIntStat::operator+=(PileIntStat& D) {
  std::cout << top << std::endl;
  while ((top < taille - 1) && !(D.est_vide())) {
    std::cout << top << std::endl;
    this->empile(D.depile());
  }
  return *this;
}

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

  p1.empile(22);
  p1.empile(22);
  p1.empile(22);
  p1.empile(22);
  p1.empile(22);
  p1.empile(22);
  p1.empile(22);

  PileIntStat p2(10);

  p2.empile(207);
  p2.empile(207);
  p2.empile(207);
  p2.empile(207);
  p2.empile(207);
  p2.empile(207);

  p1 += p2;

  std::cout << "Taille de p1: " << p1.depile() << std::endl;

  PileIntStat* p3 = new PileIntStat(10);

  delete p3;

  PileIntStat** q = new PileIntStat*[3];
  q[0] = new PileIntStat(10);
  q[1] = new PileIntStat(10);
  q[2] = new PileIntStat(10);

  delete[] q;

  return 0;
}