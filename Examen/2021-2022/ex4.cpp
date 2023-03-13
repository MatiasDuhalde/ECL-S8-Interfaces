#include <iostream>

class Compteur {
 public:
  Compteur();
  void inc();
  void dec();
  int get_valeur();

 private:
  int valeur;
};

Compteur::Compteur() { valeur = 0; }

void Compteur::inc() { valeur++; }

void Compteur::dec() {
  valeur--;
  if (valeur < 0) valeur = 0;
}

int Compteur::get_valeur() { return valeur; }

class Compteur_borne : public Compteur {
 public:
  Compteur_borne(int borne);
  void inc();

 private:
  int borne;
};

Compteur_borne::Compteur_borne(int borne) : Compteur() { this->borne = borne; }

void Compteur_borne::inc() {
  if (Compteur::get_valeur() < borne) {
    Compteur::inc();
  }
}

int main() {
  Compteur c1;
  Compteur_borne c2(10);

  c1.inc();

  for (int i = 0; i < 20; i++) {
    c2.inc();
  }
  c2.dec();

  std::cout << "Valeur de c1: " << c2.get_valeur() << std::endl;
}