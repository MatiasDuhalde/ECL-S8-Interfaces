#ifndef SUDOKU_H
#define SUDOKU_H

#include <QObject>
#include <array>
#include <bitset>
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
  Q_INVOKABLE const void reset(const bool emitSignal = true);
  Q_INVOKABLE const void clear();

  const void getArrayFromLevel(const Levels& level);

  Q_INVOKABLE const void initFromLevel(const Levels& level);
  Q_INVOKABLE const void initFromSaveFile(const QString& filename);
  Q_INVOKABLE const void saveToFile(const QString& filename) const;

  const void initFromFile(const std::string& filename);
  const void writeToFile(const std::string& filename) const;

  const bool checkCorrect(const bool emitSignal = true);
  const void checkForConflicts(const int i, const int j,
                               const bool emitSignal = true);

  Q_INVOKABLE const int getCaseValue(const int i, const int j) const;
  Q_INVOKABLE const void setCaseValue(const int i, const int j, const int value,
                                      const bool emitSignal = true);
  Q_INVOKABLE const std::array<bool, N2> getPossibleValues(const int i,
                                                           const int j) const;
  Q_INVOKABLE const void togglePossibleValue(const int i, const int j,
                                             const int value);
  Q_INVOKABLE const void removePossibleValue(const int i, const int j,
                                             const int value);
  Q_INVOKABLE const void clearPossibleValues(const int i, const int j);

  Q_INVOKABLE const bool isCaseFixed(const int i, const int j) const;
  const void setCaseFixed(const int i, const int j, const bool value);

  const std::bitset<3 * N2> getCaseConflicts(const int i, const int j) const;
  Q_INVOKABLE const bool isCaseConflicting(const int i, const int j) const;

  const bool isCaseEmpty(const int i, const int j) const;

  const void setCasesLeft(const int value);

  friend std::ostream& operator<<(std::ostream& os, const Sudoku& S);

  const void emitPossibleValuesChanged(
      const int i, const int j,
      const std::array<bool, N2> possibleValues) const;

 signals:
  void caseChanged(const int i, const int j, const int value) const;
  void possibleValuesChanged(const int i, const int j,
                             const QList<bool> possibleValues) const;
  void correct() const;
  void boardReady() const;
  void error(const QString& message) const;
  void caseConflictStatusChanged(const int i, const int j,
                                 const bool status) const;

 private:
  std::array<std::array<int, N2>, N2> grid = {0};
  std::array<std::array<bool, N2>, N2> fixedCases = {false};
  std::array<std::array<std::bitset<3 * N2>, N2>, N2> conflictingCases = {0};
  std::array<std::array<std::bitset<3 * N2>, N2>, N2> possibleValues = {0};
  bool isComplete = false;
  bool isCorrect = false;
  int casesLeft = N2 * N2;
};

#endif  // SUDOKU_H
