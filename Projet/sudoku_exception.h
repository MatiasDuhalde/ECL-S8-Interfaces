#include <string>

class SudokuException : public std::exception {
 public:
  SudokuException(const std::string& message) : message(message) {}
  virtual const char* what() const throw() { return message.c_str(); }

 private:
  std::string message;
};
