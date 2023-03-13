#include <iostream>

class Entier {
 public:
  Entier();
  Entier(int);
  ~Entier();
  Entier(const Entier&);

  Entier& operator=(const Entier&);
  Entier& operator=(int);

  friend std::ostream& operator<<(std::ostream&, const Entier&);

 private:
  int* valeur;
};

Entier& Entier::operator=(const Entier& e) {
  delete valeur;
  valeur = new int;
  *valeur = *e.valeur;
  return *this;
}

Entier& Entier::operator=(int i) {
  delete valeur;
  valeur = new int;
  *valeur = i;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Entier& e) {
  os << *e.valeur;
  return os;
}

Entier::Entier(int valeur) {
  this->valeur = new int;
  *this->valeur = valeur;
}

int main() {
  Entier e1;
  Entier e2(20);

  std::cout << "e1: " << e1 << std::endl;
  std::cout << "e2: " << e2 << std::endl;

  e1 = e2;

  std::cout << "e1: " << e1 << std::endl;
  std::cout << "e2: " << e2 << std::endl;

  Entier e3(e2);

  std::cout << "e3: " << e3 << std::endl;

  e3 = 30;

  std::cout << "e3: " << e3 << std::endl;

  Entier* e4 = new Entier(40);

  std::cout << "e4: " << *e4 << std::endl;

  delete e4;

  return 0;
}