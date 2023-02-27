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

  DamierDynG<T>& operator=(const DamierDynG<T>& D);
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

}  // namespace damier
