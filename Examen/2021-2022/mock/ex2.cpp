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

// 1
int main() {
  Nombre n1, n2(10);
  n1.set_valeur(30);
  Nombre n3(n1);
  n3 = n1 + n2;
  n3 = n3 - n1;
  n3 += n1;
  std::cout << n1 << n2 << n3;
  return 0;
}

// 2
int main() {
  Nombre n1(15), n2(8);
  std::cout << n1 << n2;
  // subtraction between an int and a Nombre is not defined
  n2 = 9 - n1;
  std::cout << n1 << n2;
  return 0;
}

int main() {
  Nombre n1(15), n2(n1);
  std::cout << n1 << n2;
  n1.set_valeur(30);
  std::cout << n1 << n2;
  return 0;
}

int main() {
  Nombre *n1(20), n2(10);
  std::cout << *n1 << n2;
  n1->set_valeur(30);
  std::cout << *n1 << n2;
  return 0;
}