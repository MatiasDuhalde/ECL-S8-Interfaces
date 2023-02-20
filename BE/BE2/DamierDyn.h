#include <iostream>

namespace damier {

class DamierDyn {
 private:
  int n;
  int m;
  int default_value;
  int** tableau;

 public:
  DamierDyn(int a, int b, int val = 0);
  DamierDyn(const DamierDyn& D);
  ~DamierDyn();
  void operator=(const DamierDyn& D);
  void Init(int val);
  void Set(int i, int j, int val);
  void Print();
  void Redim(int a, int b);
};

}  // namespace damier
