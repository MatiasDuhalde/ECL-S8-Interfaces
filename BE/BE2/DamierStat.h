#include <iostream>

namespace damier {

class DamierStat {
 private:
  int tableau[4][5];

 public:
  DamierStat();
  void Init(int val);
  void Set(int i, int j, int val);
  void Print();
};

}  // namespace damier
