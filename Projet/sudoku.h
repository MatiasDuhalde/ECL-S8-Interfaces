#ifndef SUDOKU_H
#define SUDOKU_H

#include <QObject>
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr int N = 3;
constexpr int N2 = N * N;

class Sudoku : public QObject {
  Q_OBJECT

 public:
  enum Levels { Beginner, Easy, Intermediate, Expert };
  Q_ENUM(Levels)

  Sudoku(QObject* parent = nullptr);
  Sudoku(const std::array<std::array<int, N2>, N2>& initGrid,
         QObject* parent = nullptr);
  Sudoku(const Sudoku& S, QObject* parent = nullptr);
  Sudoku(const Levels& level, QObject* parent = nullptr);

  const void init(const std::array<std::array<int, N2>, N2>& initGrid);

  static const std::array<std::array<int, N2>, N2> getArrayFromLevel(
      const Levels& level);

  Q_INVOKABLE const void initFromLevel(const Levels& level);
  Q_INVOKABLE const void initFromSaveFile(const QString& filename);

  static const std::array<std::array<int, N2>, N2> readFromFile(
      const std::string& filename);
  const void writeToFile(const std::string& filename) const;

  const bool checkCorrect(const bool emitSignal = true);
  const void checkForConflicts(const int i, const int j,
                               const bool emitSignal = true);

  Q_INVOKABLE const int getCaseValue(const int i, const int j) const;
  Q_INVOKABLE const void setCaseValue(const int i, const int j, const int value,
                                      const bool emitSignal = true);

  Q_INVOKABLE const bool isCaseFixed(const int i, const int j) const;
  const void setCaseFixed(const int i, const int j, const bool value);

  const bool isCaseEmpty(const int i, const int j) const;

  const void setCasesLeft(const int value);

  friend std::ostream& operator<<(std::ostream& os, const Sudoku& S);

 signals:
  void caseChanged(const int i, const int j, const int value);
  void correct();
  void boardReady();
  void error(const QString& message);
  void caseConflictStatusChanged(const int i, const int j, const bool status);

 private:
  std::array<std::array<int, N2>, N2> grid;
  std::array<std::array<bool, N2>, N2> fixedCases = {false};
  std::array<std::array<int, N2>, N2> conflictingCases = {0};
  bool isComplete = false;
  bool isCorrect = false;
  int casesLeft = N2;
};

#endif  // SUDOKU_H
