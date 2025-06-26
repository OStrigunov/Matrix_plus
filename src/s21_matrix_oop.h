#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double **matrix_;

  // Приватные вспомогательные функции
  void createMatrix(int rows, int cols);
  void freeMatrix();
  S21Matrix MatrixMinor(int row, int col);

 public:
  // Конструкторы и деструктор
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  // Методы для операций над матрицами
  bool EqMatrix(const S21Matrix &other);
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // getters
  int GetRows() const;
  int GetCols() const;
  // setters
  void SetRows(int rows);
  void SetCols(int cols);

  // Перегрузка операторов
  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double num);
  friend S21Matrix operator*(double num, S21Matrix &matrix);
  double &operator()(int i, int j);
};

#endif  // S21_MATRIX_OOP_H_