#include <iostream>

namespace damier {

class DamierDyn {
 private:
  int n;
  int m;
  int default_value;
  int** tableau;

 public:
  DamierDyn(int a, int b, int val);
  DamierDyn(const DamierDyn& D);
  ~DamierDyn();
  void operator=(const DamierDyn& D);
  void Init(int val);
  void Set(int i, int j, int val);
  void Print();
  void Redim(int a, int b);
};

DamierDyn::DamierDyn(int a, int b, int val = 0) {
  n = a;
  m = b;
  default_value = val;
  tableau = new int*[n];
  for (int i = 0; i < n; i++) {
    tableau[i] = new int[m];
    for (int j = 0; j < m; j++) Set(i, j, default_value);
  }
}

DamierDyn::DamierDyn(const DamierDyn& D) {
  n = D.n;
  m = D.m;
  default_value = D.default_value;
  tableau = new int*[n];
  for (int i = 0; i < n; i++) {
    tableau[i] = new int[m];
    for (int j = 0; j < m; j++) Set(i, j, D.tableau[i][j]);
  }
}

DamierDyn::~DamierDyn() {
  for (int i = 0; i < n; i++) delete[] tableau[i];

  delete[] tableau;
}

void DamierDyn::Init(int val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, val);
}

void DamierDyn::Set(int i, int j, int val) { tableau[i][j] = val; }

void DamierDyn::Print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << tableau[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void DamierDyn::Redim(int a, int b) {
  int** tableau2 = new int*[a];
  for (int i = 0; i < a; i++) {
    tableau2[i] = new int[b];
    for (int j = 0; j < b; j++) {
      if (i < n && j < m)
        tableau2[i][j] = tableau[i][j];
      else
        tableau2[i][j] = default_value;
    };
  }

  for (int i = 0; i < n; i++) delete[] tableau[i];
  delete[] tableau;

  tableau = tableau2;
  n = a;
  m = b;
}

// operator= (redimensionnement de D2 à l'image de D1)
void DamierDyn::operator=(const DamierDyn& D) { Redim(D.n, D.m); }

}  // namespace damier
