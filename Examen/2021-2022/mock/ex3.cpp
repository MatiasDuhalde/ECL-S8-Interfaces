#include <iostream>

class Nombre {
 private:
  int valeur;

 public:
  Nombre();
  Nombre(int v);
  Nombre(const Nombre& n);

  void set_valeur(int v);
  int get_valeur();

  Nombre& operator=(const Nombre& n);
  Nombre& operator+=(const Nombre& n);
  Nombre operator+(const Nombre& n);
  Nombre operator-(const Nombre& n);

  friend std::ostream& operator<<(std::ostream& os, const Nombre& n);
};

Nombre::Nombre(const Nombre& n) { this->valeur = n.valeur; }