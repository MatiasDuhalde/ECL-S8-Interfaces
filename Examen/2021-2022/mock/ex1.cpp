#include <iostream>

// Vecteur2D
class Vecteur2D {
 private:
  int x, y;

 public:
  Vecteur2D(int x, int y);

  void set_valeurs(int x, int y);
  void get_valeurs(int &x, int &y);
};

Vecteur2D::Vecteur2D(int x, int y) {
  this->x = x;
  this->y = y;
}

void Vecteur2D::set_valeurs(int x, int y) {
  this->x = x;
  this->y = y;
}

void Vecteur2D::get_valeurs(int &x, int &y) {
  x = this->x;
  y = this->y;
}

class Vecteur3D : public Vecteur2D {
 private:
  int z;

 public:
  Vecteur3D(int x, int y, int z);

  void set_valeurs(int x, int y, int z);
  void get_valeurs(int &x, int &y, int &z);
};

// Vector2D constructor must be called
// Vecteur3D::Vecteur3D(int x, int y, int z) {
Vecteur3D::Vecteur3D(int x, int y, int z) : Vecteur2D(x, y) {
  Vecteur2D::set_valeurs(x, y);
  this->z = z;
}

void Vecteur3D::set_valeurs(int x, int y, int z) {
  Vecteur2D::set_valeurs(x, y);
  this->z = z;
}

void Vecteur3D::get_valeurs(int &x, int &y, int &z) {
  // x and y are private in Vecteur2D
  // x = this->x;
  // y = this->y;
  Vecteur2D::get_valeurs(x, y);
  z = this->z;
}

int main() {
  Vecteur2D v1(1, 2);
  Vecteur2D v2(3, 4);

  int x, y, z;

  v1.get_valeurs(x, y);
  std::cout << "v1: " << x << ", " << y << std::endl;

  v2.get_valeurs(x, y);
  std::cout << "v2: " << x << ", " << y << std::endl;

  Vecteur3D v3(5, 6, 7);

  v3.get_valeurs(x, y, z);
  std::cout << "v3: " << x << ", " << y << ", " << z << std::endl;

  return 0;
}