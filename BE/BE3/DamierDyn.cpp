#include "DamierDyn.h"

namespace damier {

DamierDyn::DamierDyn(const int a, const int b, const int val = 0) {
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

DamierDyn& DamierDyn::operator=(const DamierDyn& D) {
  Redim(D.n, D.m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, D.tableau[i][j]);

  return *this;
}

DamierDyn DamierDyn::operator+(const DamierDyn& D) {
  DamierDyn D2(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) D2.Set(i, j, tableau[i][j] + D.tableau[i][j]);
  return D2;
}

void DamierDyn::operator+=(const DamierDyn& D) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, tableau[i][j] + D.tableau[i][j]);
}

void DamierDyn::operator+=(const int val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, tableau[i][j] + val);
}

std::ostream& operator<<(std::ostream& os, const DamierDyn& D) {
  for (int i = 0; i < D.n; i++) {
    for (int j = 0; j < D.m; j++) os << D.tableau[i][j] << " ";
    os << std::endl;
  }
  return os;
}

void DamierDyn::Init(const int val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, val);
}

void DamierDyn::Set(const int i, const int j, const int val) {
  tableau[i][j] = val;
}

void DamierDyn::Print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << tableau[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void DamierDyn::Redim(const int a, const int b) {
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

}  // namespace damier
