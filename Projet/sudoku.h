#ifndef SUDOKU_H
#define SUDOKU_H

#include <QObject>
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr int N = 9;

class Sudoku : public QObject {
  Q_OBJECT
 public:
  enum Levels { Beginner, Easy, Intermediate, Expert };
  Q_ENUM(Levels)

  Sudoku(QObject* parent = nullptr);
  Sudoku(const std::array<std::array<int, N>, N> grid,
         QObject* parent = nullptr);
  Sudoku(const Sudoku& S, QObject* parent = nullptr);
  void init(const std::array<std::array<int, N>, N>);
  Q_INVOKABLE void initLevel(const Levels level);
  friend std::ostream& operator<<(std::ostream& os, const Sudoku& S);
  const std::array<std::array<int, N>, N> readFromFile(
      const std::string& filename);
  void writeToFile(const std::string& filename);
  bool isSolved();
  bool isCorrect();
  int get(const int i, const int j);
  void set(const int i, const int j, const int val,
           const bool emitSignal = true);

  int myGet() { return get(0, 0); };
  void mySet(const int val) { set(0, 0, val); };
  Q_INVOKABLE int getCase(const int i, const int j) { return this->get(i, j); };
  Q_INVOKABLE void setCase(const int i, const int j, const int val,
                           const bool emitSignal = true) {
    this->set(i, j, val, emitSignal);
  };

  Q_PROPERTY(const int qweasd READ get WRITE mySet NOTIFY caseChanged)

 signals:
  void caseChanged(const int i, const int j);

 private:
  std::array<std::array<int, N>, N> grid;
  std::array<std::array<bool, N>, N> fixed;
};

#endif  // SUDOKU_H