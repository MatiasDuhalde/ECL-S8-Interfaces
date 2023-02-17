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
  Sudoku(QObject* parent = nullptr);
  Sudoku(const int grid[N][N], QObject* parent = nullptr);
  Sudoku(const Sudoku& S, QObject* parent = nullptr);
  void init(const int grid[N][N]);
  friend std::ostream& operator<<(std::ostream& os, const Sudoku& S);
  Sudoku readFromFile(const std::string& filename, QObject* parent = nullptr);
  void writeToFile(const std::string& filename);
  bool isSolved();
  bool isCorrect();
  Q_INVOKABLE void set(const int i, const int j, const int val,
                       const bool emitSignal = true);
  int get(const int i, const int j);

  // Q_PROPERTY(int grid READ get(int a, int b) WRITE set NOTIFY gridChanged())

 signals:
  void gridChanged(const int i, const int j, const int val);

 private:
  int grid[N][N];
  bool fixed[N][N];
};

#endif  // SUDOKU_H