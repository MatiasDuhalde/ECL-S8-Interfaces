#include "ExceptionDamier.h"

namespace damier {

ExceptionDamier::ExceptionDamier(std::string msg) : std::exception() {
  this->answer += __PRETTY_FUNCTION__;
  this->answer += " : ";
  this->answer += msg;
}

ExceptionDamier::~ExceptionDamier() {}

const char* ExceptionDamier::what() {
  std::cerr << this->answer << std::endl;
  return this->answer.c_str();
}

}  // namespace damier
