#include "sudoku.h"

Sudoku::Sudoku(QObject* parent) : QObject{parent} {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = 0;
      fixed[i][j] = false;
    }
  }
}

Sudoku::Sudoku(const std::array<std::array<int, N>, N> grid, QObject* parent)
    : QObject{parent} {
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

void Sudoku::init(const std::array<std::array<int, N>, N> grid) {
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

void Sudoku::initLevel(const Levels level) {
  switch (level) {
    case Beginner:
      this->init(this->readFromFile("boards/grilleDebutant.csv"));
      break;
    case Easy:
      this->init(this->readFromFile("boards/grilleFacile.csv"));
      break;
    case Intermediate:
      this->init(this->readFromFile("boards/grilleIntermediaire.csv"));
      break;
    case Expert:
      this->init(this->readFromFile("boards/grilleExpert.csv"));
      break;
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

const std::array<std::array<int, N>, N> Sudoku::readFromFile(
    const std::string& filename) {
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
  std::array<std::array<int, N>, N> grid;
  int i = 0;
  while (std::getline(file, line)) {
    // Ignore lines that are empty or start with a #
    if (line.empty() || line[0] == '#') {
      continue;
    }
    // Split the line into tokens
    std::stringstream ss(line);
    std::string token;
    int j = 0;
    while (std::getline(ss, token, '|')) {
      if (token == ".") {
        grid[i][j] = 0;
      } else {
        grid[i][j] = std::stoi(token);
      }
      j++;
    }
    i++;
  }
  return grid;
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
  std::cout << "set(" << i << ", " << j << ", " << val << ")" << std::endl;
  if (fixed[i][j]) {
    return;
  }
  grid[i][j] = val;
  if (emitSignal) {
    emit caseChanged(i, j);
  }
}

int Sudoku::get(const int i, const int j) {
  std::cout << "get(" << i << ", " << j << ")" << std::endl;
  return grid[i][j];
}
