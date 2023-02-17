#ifndef SUDOKU_H
#define SUDOKU_H

#include <QObject>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

constexpr int N = 9;

class Sudoku : public QObject {
  Q_OBJECT
 public:
  Sudoku(int grid[N][N], QObject* parent = nullptr);
  Sudoku(const Sudoku& S, QObject* parent = nullptr);
  friend std::ostream& operator<<(std::ostream& os, const Sudoku& S);
  Sudoku readFromFile(const std::string& filename);
  void writeToFile(const std::string& filename);
  bool isSolved();
  bool isCorrect();
  Q_INVOKABLE void set(int i, int j, int val, bool emitSignal = true);
  int get(int i, int j);

  // Q_PROPERTY(int grid READ get(int a, int b) WRITE set NOTIFY gridChanged)

 signals:
  void gridChanged();

 private:
  int grid[N][N];
};

#endif  // SUDOKU_H