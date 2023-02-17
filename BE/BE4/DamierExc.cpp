#include <iostream>

namespace damier {

class DamierExc {
 private:
  int n;
  int m;
  int default_value;
  int** tableau;

 public:
  DamierExc(const int a, const int b, const int val);
  DamierExc(const DamierExc& D);
  ~DamierExc();
  void operator=(const DamierExc& D);
  DamierExc operator+(const DamierExc& D);
  void operator+=(const DamierExc& D);
  void operator+=(const int val);
  friend std::ostream& operator<<(std::ostream& os, const DamierExc& D);
  void Init(const int val);
  void Set(const int i, const int j, const int val);
  void Print();
  void Redim(const int a, const int b);
};

DamierExc::DamierExc(const int a, const int b, const int val = 0) {
  n = a;
  m = b;
  default_value = val;
  tableau = new int*[n];
  for (int i = 0; i < n; i++) {
    tableau[i] = new int[m];
    for (int j = 0; j < m; j++) Set(i, j, default_value);
  }
}

DamierExc::DamierExc(const DamierExc& D) {
  n = D.n;
  m = D.m;
  default_value = D.default_value;
  tableau = new int*[n];
  for (int i = 0; i < n; i++) {
    tableau[i] = new int[m];
    for (int j = 0; j < m; j++) Set(i, j, D.tableau[i][j]);
  }
}

DamierExc::~DamierExc() {
  for (int i = 0; i < n; i++) delete[] tableau[i];

  delete[] tableau;
}

void DamierExc::operator=(const DamierExc& D) {
  Redim(D.n, D.m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, D.tableau[i][j]);
}

DamierExc DamierExc::operator+(const DamierExc& D) {
  DamierExc D2(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) D2.Set(i, j, tableau[i][j] + D.tableau[i][j]);
  return D2;
}

void DamierExc::operator+=(const DamierExc& D) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, tableau[i][j] + D.tableau[i][j]);
}

void DamierExc::operator+=(const int val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, tableau[i][j] + val);
}

std::ostream& operator<<(std::ostream& os, const DamierExc& D) {
  for (int i = 0; i < D.n; i++) {
    for (int j = 0; j < D.m; j++) os << D.tableau[i][j] << " ";
    os << std::endl;
  }
  return os;
}

void DamierExc::Init(const int val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, val);
}

void DamierExc::Set(const int i, const int j, const int val) {
  if (i < 0 || i >= n || j < 0 || j >= m) throw "Out of bounds";
  if (val > default_value) throw "Value too high";
  tableau[i][j] = val;
}

void DamierExc::Print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << tableau[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void DamierExc::Redim(const int a, const int b) {
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
