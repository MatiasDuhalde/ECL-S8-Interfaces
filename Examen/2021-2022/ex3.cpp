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