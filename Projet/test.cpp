#include <iostream>

#include "sudoku.h"

int main() {
  Sudoku sudoku;
  // QString filename = "boards/grilleFacile.csv";

  // sudoku.initFromSaveFile(filename);

  sudoku.initFromLevel(Sudoku::Levels::Expert);

  std::cout << sudoku;

  return 0;
}