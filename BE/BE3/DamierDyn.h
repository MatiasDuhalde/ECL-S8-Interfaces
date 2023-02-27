#include <iostream>

namespace damier {

class DamierDyn {
 private:
  int n;
  int m;
  int default_value;
  int** tableau;

 public:
  DamierDyn(const int a, const int b, const int val);
  DamierDyn(const DamierDyn& D);
  ~DamierDyn();

  DamierDyn& operator=(const DamierDyn& D);
  DamierDyn operator+(const DamierDyn& D);
  void operator+=(const DamierDyn& D);
  void operator+=(const int val);
  friend std::ostream& operator<<(std::ostream& os, const DamierDyn& D);

  void Init(const int val);
  void Set(const int i, const int j, const int val);
  void Print();
  void Redim(const int a, const int b);
};

}  // namespace damier
