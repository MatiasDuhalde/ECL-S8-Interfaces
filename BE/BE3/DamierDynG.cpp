#include <iostream>

namespace damier {

template <typename T>
class DamierDynG {
 private:
  int n;
  int m;
  T default_value;
  T** tableau;

 public:
  DamierDynG(int a, int b, const T val);
  DamierDynG(const DamierDynG<T>& D);
  ~DamierDynG();
  void operator=(const DamierDynG<T>& D);
  DamierDynG<T> operator+(const DamierDynG<T>& D);
  void operator+=(const DamierDynG<T>& D);
  void operator+=(const T val);
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, const DamierDynG<U>& D);
  void Init(const T val);
  void Set(int i, int j, const T val);
  void Print();
  void Redim(int a, int b);
};

template <typename T>
DamierDynG<T>::DamierDynG(const int a, const int b, const T val) {
  n = a;
  m = b;
  default_value = val;
  tableau = new T*[n];
  for (int i = 0; i < n; i++) {
    tableau[i] = new T[m];
    for (int j = 0; j < m; j++) Set(i, j, default_value);
  }
}

template <typename T>
DamierDynG<T>::DamierDynG(const DamierDynG& D) {
  n = D.n;
  m = D.m;
  default_value = D.default_value;
  tableau = new T*[n];
  for (int i = 0; i < n; i++) {
    tableau[i] = new T[m];
    for (int j = 0; j < m; j++) Set(i, j, D.tableau[i][j]);
  }
}

template <typename T>
DamierDynG<T>::~DamierDynG() {
  for (int i = 0; i < n; i++) delete[] tableau[i];

  delete[] tableau;
}

template <typename T>
void DamierDynG<T>::operator=(const DamierDynG& D) {
  Redim(D.n, D.m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, D.tableau[i][j]);
}

template <typename T>
DamierDynG<T> DamierDynG<T>::operator+(const DamierDynG& D) {
  DamierDynG D2(n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) D2.Set(i, j, tableau[i][j] + D.tableau[i][j]);
  return D2;
}

template <typename T>
void DamierDynG<T>::operator+=(const DamierDynG& D) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, tableau[i][j] + D.tableau[i][j]);
}

template <typename T>
void DamierDynG<T>::operator+=(const T val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, tableau[i][j] + val);
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const DamierDynG<U>& D) {
  for (int i = 0; i < D.n; i++) {
    for (int j = 0; j < D.m; j++) os << D.tableau[i][j] << " ";
    os << std::endl;
  }
  return os;
}

template <typename T>
void DamierDynG<T>::Init(const T val) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) Set(i, j, val);
}

template <typename T>
void DamierDynG<T>::Set(const int i, const int j, const T val) {
  tableau[i][j] = val;
}

template <typename T>
void DamierDynG<T>::Print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cout << tableau[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

template <typename T>
void DamierDynG<T>::Redim(const int a, const int b) {
  int** tableau2 = new T*[a];
  for (int i = 0; i < a; i++) {
    tableau2[i] = new T[b];
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
