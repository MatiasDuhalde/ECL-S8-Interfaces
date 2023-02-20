#include "sudoku.h"

#include "sudoku_exception.h"

Sudoku::Sudoku(QObject* parent) : QObject{parent} {}

Sudoku::Sudoku(const std::array<std::array<int, N2>, N2>& initGrid,
               QObject* parent)
    : QObject{parent} {
  this->init(initGrid);
}

Sudoku::Sudoku(const Sudoku& S, QObject* parent) : QObject{parent} {
  this->init(S.grid);
}

Sudoku::Sudoku(const Levels& level, QObject* parent) : QObject{parent} {
  this->initFromLevel(level);
}

const void Sudoku::init(const std::array<std::array<int, N2>, N2>& initGrid) {
  this->clear();
  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N2; j++) {
      const int val = initGrid[i][j];
      this->setCaseValue(i, j, val, false);
      if (val != 0) {
        this->setCaseFixed(i, j, true);
      }
    }
  }
}

const void Sudoku::reset(const bool emitSignal) {
  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N2; j++) {
      if (!this->isCaseFixed(i, j)) {
        this->setCaseValue(i, j, 0, emitSignal);
      }
      this->clearPossibleValues(i, j);
    }
  }
}

const void Sudoku::clear() {
  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N2; j++) {
      this->grid[i][j] = 0;
      this->fixedCases[i][j] = false;
      this->conflictingCases[i][j] = 0;
      this->possibleValues[i][j] = 0;
    }
  }
  this->casesLeft = N2 * N2;
  this->isComplete = false;
  this->isCorrect = false;
}

const void Sudoku::initFromLevel(const Levels& level) {
  try {
    switch (level) {
      case Levels::Beginner:
        this->initFromFile("boards/grilleDebutant.csv");
        break;
      case Levels::Easy:
        this->initFromFile("boards/grilleFacile.csv");
        break;
      case Levels::Intermediate:
        this->initFromFile("boards/grilleIntermediaire.csv");
        break;
      case Levels::Expert:
        this->initFromFile("boards/grilleExpert.csv");
        break;
      default:
        throw SudokuException("Invalid level");
        break;
    }
    emit this->boardReady();
  } catch (SudokuException& e) {
    std::cerr << e.what() << std::endl;
    emit this->error(QString(e.what()));
  }
}

const void Sudoku::initFromSaveFile(const QString& filename) {
  try {
    this->initFromFile(filename.toStdString());
    emit this->boardReady();
  } catch (SudokuException& e) {
    std::cerr << e.what() << std::endl;
    emit this->error(QString(e.what()));
  }
}

const void Sudoku::saveToFile(const QString& filename) const {
  try {
    this->writeToFile(filename.toStdString());
  } catch (SudokuException& e) {
    std::cerr << e.what() << std::endl;
    emit this->error(QString(e.what()));
  }
}

const void Sudoku::initFromFile(const std::string& filename) {
  std::ifstream file;
  file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    file.open(filename);
  } catch (const std::ifstream::failure& e) {
    std::cerr << "Error while opening file: " << filename << std::endl;
    throw SudokuException("Could not open file");
  }

  bool gridInitialized = false;

  std::array<std::array<int, N2>, N2> newGrid;
  std::string line;
  try {
    for (int i = 0; i < N2; i++) {
      if (file.eof()) {
        throw SudokuException("Invalid file format");
      }
      std::getline(file, line);
      if (line.empty() || line[0] == '#') {
        i--;
        continue;
      }
      std::stringstream ss(line);
      std::string token;
      for (int j = 0; j < N2; j++) {
        std::getline(ss, token, '|');
        if (token == ".") {
          newGrid[i][j] = 0;
        } else if (!token.empty()) {
          newGrid[i][j] = std::stoi(token);
        } else {
          throw SudokuException("Invalid file format");
        }
      }
    }

    this->init(newGrid);
    gridInitialized = true;

    while (!file.eof()) {
      std::getline(file, line);
      if (line.empty() || line[0] == '#') {
        continue;
      }
      for (int i = 0; i < N2; i++) {
        for (int j = 0; j < N2; j++) {
          if (line[i * N2 + j] == '1') {
            this->setCaseFixed(i, j, true);
          } else if (line[i * N2 + j] == '0') {
            this->setCaseFixed(i, j, false);
          } else {
            throw SudokuException("Invalid file format");
          }
        }
      }
      break;
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error while reading file: " << filename << std::endl;
    throw SudokuException("Invalid file format");
  } catch (const std::out_of_range& e) {
    std::cerr << "Error while reading file: " << filename << std::endl;
    throw SudokuException("Invalid file format");
  } catch (const std::ifstream::failure& e) {
    if (!gridInitialized) {
      std::cerr << "Error while reading file: " << filename << std::endl;
      throw SudokuException("Invalid file format");
    }
  }
}

const void Sudoku::writeToFile(const std::string& filename) const {
  std::ofstream file(filename);
  file << *this << std::endl;
  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N2; j++) {
      file << this->fixedCases[i][j];
    }
  }
  file << std::endl;
}

const bool Sudoku::checkCorrect(const bool emitSignal) {
  if (!this->isComplete) {
    return false;
  }

  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N2; j++) {
      if (this->conflictingCases[i][j] != 0) {
        return false;
      }
    }
  }

  this->isCorrect = true;

  if (emitSignal) {
    emit correct();
  }

  return true;
}

const void Sudoku::checkForConflicts(const int i, const int j,
                                     const bool emitSignal) {
  // Anatomy of a conflict:
  // Bits (case N=3) : xxxxxxxxx xxxxxxxxx xxxxxxxxx
  // If x is 1 then there is a conflict of the current value with the value
  // corresponding to the bit.
  // The correspondances are as follows:
  // first N2 bits from right: row conflicts
  // next N2 bits from right: column conflicts
  // next N2 bits from right: subgrid conflicts

  // new array of conflicts
  std::array<std::array<std::bitset<3 * N2>, N2>, N2> newConflicts;
  for (int i = 0; i < N2; i++)
    for (int j = 0; j < N2; j++)
      newConflicts[i][j] = this->conflictingCases[i][j];

  // Check row conflicts

  int maskRow = 1 << j;
  int maskCol = 1 << (i + N2);
  int maskSubGrid = 1 << ((i % N) * N + j % N + 2 * N2);

  int conflicts = 0;
  for (int k = 0; k < N2; k++) {
    if (!this->isCaseEmpty(i, k) && k != j) {
      int mask = 1 << k;
      if (this->getCaseValue(i, j) == this->getCaseValue(i, k)) {
        conflicts |= mask;
        newConflicts[i][k] |= maskRow;
      } else {
        newConflicts[i][k] &= ~maskRow;
      }
    }
  }

  // Check column conflicts
  for (int k = 0; k < N2; k++) {
    if (!this->isCaseEmpty(k, j) && k != i) {
      int mask = 1 << (k + N2);
      if (this->getCaseValue(i, j) == this->getCaseValue(k, j)) {
        conflicts |= mask;
        newConflicts[k][j] |= maskCol;
      } else {
        newConflicts[k][j] &= ~maskCol;
      }
    }
  }

  // Check subgrid conflicts
  int subgridI = i / N;
  int subgridJ = j / N;
  for (int k = 0; k < N; k++) {
    for (int l = 0; l < N; l++) {
      int a = subgridI * N + k;
      int b = subgridJ * N + l;
      if (!this->isCaseEmpty(a, b) && (a != i || b != j)) {
        int mask = 1 << (k * N + b + 2 * N2);
        if (this->getCaseValue(i, j) == this->getCaseValue(a, b)) {
          conflicts |= mask;
          newConflicts[a][b] |= maskSubGrid;
        } else {
          newConflicts[a][b] &= ~maskSubGrid;
        }
      }
    }
  }

  newConflicts[i][j] = conflicts;

  // Update conflicts
  for (int k = 0; k < N2; k++) {
    for (int l = 0; l < N2; l++) {
      if (newConflicts[k][l] != this->conflictingCases[k][l]) {
        if ((this->conflictingCases[k][l] == 0 || newConflicts[k][l] == 0) &&
            emitSignal) {
          emit caseConflictStatusChanged(k, l, newConflicts[k][l] != 0);
        }
        this->conflictingCases[k][l] = newConflicts[k][l];
      }
    }
  }
}

const void Sudoku::setCaseValue(const int i, const int j, const int value,
                                const bool emitSignal) {
  if (this->isCaseFixed(i, j)) {
    // Case is fixed, cannot be changed
    return;
  }
  bool caseWasEmpty = this->isCaseEmpty(i, j);
  grid[i][j] = value;
  if (caseWasEmpty && value != 0) {
    // Case was empty, now it is not
    this->setCasesLeft(this->casesLeft - 1);
    this->clearPossibleValues(i, j);
  } else if (!caseWasEmpty && value == 0) {
    // Case was not empty, now it is
    this->setCasesLeft(this->casesLeft + 1);
  }
  this->checkForConflicts(i, j, emitSignal);
  if (emitSignal) {
    emit caseChanged(i, j, value);
  }

  if (this->isComplete) {
    this->checkCorrect(emitSignal);
  }
}

const int Sudoku::getCaseValue(const int i, const int j) const {
  return grid[i][j];
}

const std::array<bool, N2> Sudoku::getPossibleValues(const int i,
                                                     const int j) const {
  std::array<bool, N2> calculatedPossibleValues;
  for (int k = 0; k < N2; k++) {
    calculatedPossibleValues[k] = this->possibleValues[i][j][k];
  }
  return calculatedPossibleValues;
}

const void Sudoku::togglePossibleValue(const int i, const int j,
                                       const int value) {
  if (!this->isCaseEmpty(i, j) || value == 0) {
    // Case is not empty, cannot toggle possible values
    return;
  }
  this->possibleValues[i][j][value - 1] =
      !this->possibleValues[i][j][value - 1];
  this->emitPossibleValuesChanged(i, j, this->getPossibleValues(i, j));
}

const void Sudoku::emitPossibleValuesChanged(
    const int i, const int j, const std::array<bool, N2> values) const {
  // std::array<bool, N2> to QVariant
  QList<bool> valuesList;
  for (int k = 0; k < N2; k++) {
    valuesList.append(values[k]);
  }
  emit this->possibleValuesChanged(i, j, valuesList);
}

const void Sudoku::removePossibleValue(const int i, const int j,
                                       const int value) {
  this->possibleValues[i][j][value] = false;
}

const void Sudoku::clearPossibleValues(const int i, const int j) {
  this->possibleValues[i][j] = 0;
}

const bool Sudoku::isCaseFixed(const int i, const int j) const {
  return this->fixedCases[i][j];
}

const void Sudoku::setCaseFixed(const int i, const int j, const bool value) {
  this->fixedCases[i][j] = value;
}

const bool Sudoku::isCaseEmpty(const int i, const int j) const {
  return (this->getCaseValue(i, j) == 0);
}

const std::bitset<3 * N2> Sudoku::getCaseConflicts(const int i,
                                                   const int j) const {
  return this->conflictingCases[i][j];
}

const bool Sudoku::isCaseConflicting(const int i, const int j) const {
  return this->getCaseConflicts(i, j) != 0;
}

const void Sudoku::setCasesLeft(const int newCasesLeft) {
  this->casesLeft = newCasesLeft;
  if (this->casesLeft == 0) {
    this->isComplete = true;
  } else {
    this->isComplete = false;
  }
}

std::ostream& operator<<(std::ostream& os, const Sudoku& S) {
  for (int i = 0; i < N2; i++) {
    for (int j = 0; j < N2; j++) {
      int value = S.grid[i][j];
      if (value == 0) {
        os << ".";
      } else {
        os << value;
      }
      if (j != N2 - 1) {
        os << "|";
      }
    }
    os << std::endl;
  }
  return os;
}