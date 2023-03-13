#include "ExceptionDamier.h"

namespace damier {

ExceptionDamier::ExceptionDamier(int default_value, int value,
                                 std::string file_name,
                                 std::string function_name) throw()
    : std::exception(),
      default_value(default_value),
      value(value),
      file_name(file_name),
      function_name(function_name) {
  this->answer += "Borne = " + std::to_string(default_value) + "\n";
  this->answer += std::to_string(value) + "\n";
  this->answer += file_name + "\n";
  this->answer += function_name + "\n";
}

const char* ExceptionDamier::what() throw() { return this->answer.c_str(); }

}  // namespace damier
