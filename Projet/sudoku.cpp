#include "sudoku.h"

Sudoku::Sudoku(QObject* parent) : QObject{parent} {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = 0;
      fixed[i][j] = false;
    }
  }
}

Sudoku::Sudoku(const int grid[N][N], QObject* parent) : QObject{parent} {
  this->init(grid);
}

Sudoku::Sudoku(const Sudoku& S, QObject* parent) : QObject{parent} {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      const int val = S.grid[i][j];
      this->set(i, j, val, false);
      if (val != 0) {
        fixed[i][j] = true;
      }
    }
  }
}

void Sudoku::init(const int grid[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      const int val = grid[i][j];
      this->set(i, j, val, false);
      if (val != 0) {
        fixed[i][j] = true;
      }
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Sudoku& S) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      os << S.grid[i][j] << " ";
    }
    os << std::endl;
  }
  return os;
}

Sudoku Sudoku::readFromFile(const std::string& filename, QObject* parent) {
  // Files are in the format
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.
  // .|.|.|.|.|.|.|.|.

  std::ifstream file(filename);
  std::string line;
  int grid[N][N];
  int i = 0;
  while (std::getline(file, line)) {
    // Ignore lines that are empty or start with a #
    if (line.empty() || line[0] == '#') {
      continue;
    }

    std::istringstream iss(line);
    int j = 0;
    for (std::string s; iss >> s;) {
      // Character . represents an empty cell (0)
      // Character | is a delimiter
      if (s == "|") {
        continue;
      } else if (s == ".") {
        grid[i][j] = 0;
      } else {
        grid[i][j] = std::stoi(s);
      }
      j++;
    }
    i++;
  }
  return Sudoku(grid, parent);
}

void Sudoku::writeToFile(const std::string& filename) {
  std::ofstream file(filename);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        file << ".";
      } else {
        file << grid[i][j] << " ";
      }
      if (j != N - 1) {
        file << "|";
      }
    }
    file << std::endl;
  }
}

bool Sudoku::isSolved() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i][j] == 0) {
        return false;
      }
    }
  }
  return true;
}

bool Sudoku::isCorrect() {
  // Check rows
  for (int i = 0; i < N; i++) {
    bool seen[N + 1] = {false};
    for (int j = 0; j < N; j++) {
      if (grid[i][j] != 0) {
        if (seen[grid[i][j]]) {
          return false;
        }
        seen[grid[i][j]] = true;
      }
    }
  }

  // Check columns
  for (int j = 0; j < N; j++) {
    bool seen[N + 1] = {false};
    for (int i = 0; i < N; i++) {
      if (grid[i][j] != 0) {
        if (seen[grid[i][j]]) {
          return false;
        }
        seen[grid[i][j]] = true;
      }
    }
  }

  // Check 3x3 subgrids
  for (int i = 0; i < N; i += 3) {
    for (int j = 0; j < N; j += 3) {
      bool seen[N + 1] = {false};
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (grid[i + k][j + l] != 0) {
            if (seen[grid[i + k][j + l]]) {
              return false;
            }
            seen[grid[i + k][j + l]] = true;
          }
        }
      }
    }
  }

  return true;
}

void Sudoku::set(const int i, const int j, const int val,
                 const bool emitSignal) {
  if (fixed[i][j]) {
    return;
  }
  grid[i][j] = val;
  if (emitSignal) {
    emit gridChanged(i, j, val);
  }
}

int Sudoku::get(const int i, const int j) { return grid[i][j]; }
