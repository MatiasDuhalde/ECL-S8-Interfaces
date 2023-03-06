#include <iostream>
#include <stdexcept>
#include "ExceptionDamier.h"

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

  DamierExc& operator=(const DamierExc& D);
  DamierExc operator+(const DamierExc& D);
  void operator+=(const DamierExc& D);
  void operator+=(const int val);
  friend std::ostream& operator<<(std::ostream& os, const DamierExc& D);

  void Init(const int val) throw();
  void Set(const int i, const int j, const int val) throw();
  void Print();
  void Redim(const int a, const int b);
};

}  // namespace damier
