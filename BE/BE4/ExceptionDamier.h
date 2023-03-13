#include <iostream>
#include <stdexcept>
#include <string>

namespace damier {

class ExceptionDamier : public std::exception {
 private:
  int default_value;
  int value;
  std::string file_name;
  std::string function_name;
  std::string answer = "";

 public:
  ExceptionDamier(int default_value, int value, std::string file_name,
                  std::string function_name) throw();
  const char* what() throw();
};

}  // namespace damier
