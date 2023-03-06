#include <iostream>
#include <stdexcept>
#include <string>

namespace damier {

class ExceptionDamier : public std::exception {
 private:
  std::string answer = "";

 public:
  ExceptionDamier(std::string msg);
  ~ExceptionDamier();
  const char* what();
};

}  // namespace damier
